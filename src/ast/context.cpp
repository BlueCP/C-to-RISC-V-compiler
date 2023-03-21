#include "ast/context.hpp"


VarInfo::VarInfo(int s, std::string i, int f)
    : size(s), identifier(i), fp_offset(f) {}


Scope::Scope(std::string i) : identifier(i) {}

Scope::~Scope() {
    for (auto v : variables) {
        delete v;
    }
}

// Add a new variable to the stack frame and return the fp offset.
int Scope::new_variable(int size, std::string identifier) {
    fp_offset_tracker -= size;
    variables.push_back(new VarInfo(size, identifier, fp_offset_tracker));
    return fp_offset_tracker;
    // If the fp_offset_tracker exceeds the stack frame size, the program will have undefined behaviour.
}

VarInfo* Scope::find_variable(std::string identifier) {
    for (auto v : variables) {
        if (v->identifier == identifier) {
            return v;
        }
    }
    return nullptr;
}


Context::Context() {}

Context::~Context() {
    for (auto s : scope_stack) {
        delete s;
    }
}

// Enter a new scope and create a stack frame.
void Context::new_scope(std::ostream& os, std::string identifier) {
    scope_stack.push_back(new Scope(identifier));
    // 1. Move the stack pointer down (by STACK_FRAME_SIZE).
    os << "addi sp, sp, -" << STACK_FRAME_SIZE << std::endl;
    // 2. Push the return address to the stack.
    //   - this is redunant in most cases, but it simplifes implementation to
    //     just do it every time.
    os << "sw ra, 0(sp)" << std::endl;

    // 3. Push the frame pointer to the stack.
    os << "sw fp, 4(sp)" << std::endl;

    // 4. Move the frame pointer up (to the bottom of the previous stack frame).
    os << "addi fp, sp, " << STACK_FRAME_SIZE << std::endl;
    os << "addi sp, sp, 8" << std::endl;
}

// Leave the current scope and deallocate the stack frame.
void Context::leave_scope(std::ostream& os) {
    delete scope_stack.back();
    scope_stack.pop_back();
    // 1. Load the return address from the stack.
    os << "lw ra, 0(sp)" << std::endl;
    // 2. Load the frame pointer from the stack.
    os << "lw fp, 4(sp)" << std::endl;
    // 3. Move the stack pointer up to deallocate the stack frame.
    os << "addi sp, sp, " << STACK_FRAME_SIZE << std::endl;
}

bool Context::in_global() {
    return scope_stack.size() == 0;
    // Being in global scope is equivalent to there not being any stack frames (I think)
}

// Returns the next available register. Useful for temporary results in calculations.
// NOTE: Every get_reg should be matched with a free_reg.
int Context::get_reg() {
    for (int i = 0; i < 32; i++) {
        if (reg_available[i]) {
            reg_available[i] = false;
            return i;
        }
    }
    return 10; // In future expand on this function to avoid this happening (somehow).
}

// Returns the next available register after having set it to zero.
// NOTE: Every get_clean_reg should be matched with a free_reg.
int Context::get_clean_reg(std::ostream& os) {
    int reg = get_reg();
    // TODO codegen set this reg to 0.
    os << "addi, " << reg_name[reg] << ", zero, 0" << std::endl;
    return reg;
}

// Marks a given register as available.
void Context::free_reg(int reg_id) {
    reg_available[reg_id] = true;
}

// Prepares to create a new variable of given size in the current stack frame.
// Returns the fp offset.
int Context::new_variable(int size, std::string identifier) {
    return scope_stack.back()->new_variable(size, identifier);
}

// Returns the fp offset of a variable relative to the current fp.
int Context::find_fp_offset(std::string identifier) {
    VarInfo* var = nullptr;
    int depth = 0;
    for (int i = scope_stack.size() - 1; i >= 0; i--) {
        VarInfo* v = scope_stack[i]->find_variable(identifier);
        if (v != nullptr) {
            var = v;
            depth = scope_stack.size() - 1 - i; // Depth: 0, 1, 2, ...
        }
    }
    if (var == nullptr) {
        return -1; // -1 must be an invalid value as it is not a multiple of 4.
    } else {
        return var->fp_offset + (STACK_FRAME_SIZE * depth);
        // Since fp_offset is relative to the variable's own stack frame, not the current one,
        // we have to readjust it by counting how many frames deep we have to go.
    }
}

// Stores a register in the stack using the given fp offset.
// Used for both initialising (with new_variable) and reassigning (with find_fp_offset).
void Context::store_reg(std::ostream& os, int reg, int fp_offset) {
    // fp + fp_offset + array_offset_reg = address to target
    os << "sw " << reg_name[reg] <<  ", fp(" << fp_offset + array_offset_reg << ")" << std::endl;
}

// Loads a register from the stack using the given fp offset.
// Used together with find_fp_offset.
void Context::load_reg(std::ostream& os, int reg, int fp_offset) {
    // fp + fp_offset + array_offset_reg = address to target
    os << "lw " << reg_name[reg] << ", fp(" << fp_offset + array_offset_reg << ")" << std::endl;
}
