#include "ast/context.hpp"


VarInfo::VarInfo(int s, std::string i, int f)
    : size(s), identifier(i), fp_offset(f) {}


Scope::Scope() {}

Scope::~Scope() {
    for (auto v : variables) {
        delete v;
    }
}

int Scope::new_variable(int size, std::string identifier, int frame_offset) {
    scope_offset -= size;
    variables.push_back(new VarInfo(size, identifier, scope_offset + frame_offset));
    return frame_offset + scope_offset;
}

VarInfo* Scope::find_variable(std::string identifier) {
    for (auto v : variables) {
        if (v->identifier == identifier) {
            return v;
        }
    }
    return nullptr;
}


Frame::Frame() {
    scope_stack.push_back(new Scope()); // Initial scope.
}

Frame::~Frame() {
    for (auto s : scope_stack) {
        delete s;
    }
}

void Frame::new_scope() {
    frame_offset += scope_stack.back()->scope_offset;
    scope_stack.push_back(new Scope());
}

void Frame::leave_scope() {
    frame_offset -= scope_stack.back()->scope_offset;
    delete scope_stack.back();
    scope_stack.pop_back();
}

int Frame::new_variable(int size, std::string identifier) {
    return scope_stack.back()->new_variable(size, identifier, frame_offset);
    // If the total fp offset exceeds the stack frame size, the program will have undefined behaviour.
}

VarInfo* Frame::find_variable(std::string identifier) {
    // Iterate backwards through scopes.
    for (int i = scope_stack.size() - 1; i >= 0; i--) {
        VarInfo* v = scope_stack[i]->find_variable(identifier);
        if (v != nullptr) {
            return v;
        }
    }
    return nullptr;
}


Context::Context() {}

Context::~Context() {
    for (auto s : frame_stack) {
        delete s;
    }
}

void Context::new_frame(std::ostream& os) {
    frame_stack.push_back(new Frame());
    // 1. Move the stack pointer down (by STACK_FRAME_SIZE).
    os << "addi sp, sp, -" << STACK_FRAME_SIZE << std::endl;
    // 2. Push the return address to the stack.
    //   - this is redunant in most cases, but it simplifes implementation to
    //     just do it every time.
    os << "sw ra, 0(sp)" << std::endl;

    // 3. Push the frame pointer to the stack.
    os << "sw fp, 4(sp)" << std::endl;

    // Push all saved registers to the stack.
    os << "sw s1, 8(sp)" << std::endl;
    for (int i = 0; i < 10; i++) {
        os << "sw s" << i + 2 << ", " << 12 + (4*i) << "(sp)" << std::endl;
    }

    // 4. Move the frame pointer up (to the bottom of the previous stack frame).
    os << "addi fp, sp, " << STACK_FRAME_SIZE << std::endl;
    // os << "addi sp, sp, 8" << std::endl;
}

void Context::leave_frame(std::ostream& os) {
    delete frame_stack.back();
    frame_stack.pop_back();
    // 1. Load the return address from the stack.
    os << "lw ra, 0(sp)" << std::endl;
    // 2. Load the frame pointer from the stack.
    os << "lw fp, 4(sp)" << std::endl;
    // 3. Pop all saved registers from the stack.
    os << "lw s1, 8(sp)" << std::endl;
    for (int i = 0; i < 10; i++) {
        os << "lw s" << i + 2 << ", " << 12 + (4*i) << "(sp)" << std::endl;
    }
    // 4. Move the stack pointer up to deallocate the stack frame.
    os << "addi sp, sp, " << STACK_FRAME_SIZE << std::endl;
}

void Context::new_scope() {
    frame_stack.back()->new_scope();
}

void Context::leave_scope() {
    frame_stack.back()->leave_scope();
}

int Context::new_variable(int size, std::string identifier) {
    return frame_stack.back()->new_variable(size, identifier);
}

bool Context::in_global() {
    return frame_stack.size() == 0;
    // Being in global scope is equivalent to there not being any stack frames (I think)
}

int Context::get_reg() {
    for (int i = 0; i < 32; i++) {
        if (reg_available[i]) {
            reg_available[i] = false;
            return i;
        }
    }
    return 10; // In future expand on this function to avoid this happening (somehow).
}

int Context::get_clean_reg(std::ostream& os) {
    int reg = get_reg();
    os << "addi " << reg_name[reg] << ", zero, 0" << std::endl;
    return reg;
}

void Context::free_reg(int reg_id) {
    reg_available[reg_id] = true;
}

int Context::find_fp_offset(std::string identifier) {
    VarInfo* var = frame_stack.back()->find_variable(identifier);
    if (var == nullptr) {
        return -1; // -1 is an invalid value as it is not a multiple of 4.
    } else {
        return var->fp_offset;
    }
}

VarInfo* Context::find_global_var(std::string identifier) {
    for (auto v : global_variables) {
        if (v->identifier == identifier) {
            return v;
        }
    }
    return nullptr;
}

// int Context::find_fp_offset(std::string identifier) {
//     VarInfo* var = nullptr;
//     int depth = 0;
//     for (int i = frame_stack.size() - 1; i >= 0; i--) {
//         VarInfo* v = frame_stack[i]->find_variable(identifier);
//         if (v != nullptr) {
//             var = v;
//             depth = frame_stack.size() - 1 - i; // Depth: 0, 1, 2, ...
//             break;
//         }
//     }
//     if (var == nullptr) {
//         return -1; // -1 must be an invalid value as it is not a multiple of 4.
//     } else {
//         return var->fp_offset + (STACK_FRAME_SIZE * depth);
//         // Since fp_offset is relative to the variable's own stack frame, not the current one,
//         // we have to readjust it by counting how many frames deep we have to go.
//     }
// }

void Context::store_reg(std::ostream& os, int reg, int fp_offset) {
    // fp + fp_offset + array_offset_reg = address to target
    if (array_indexing) {
        os << "slli " << reg_name[array_offset_reg] << ", " << reg_name[array_offset_reg] << ", 2" << std::endl;
        // Convert array offset to byte addressing offset
        os << "add " << reg_name[array_offset_reg] << ", " << reg_name[array_offset_reg] << ", fp" << std::endl;
        // Add fp and array offset
        os << "sw " << reg_name[reg] << ", " << fp_offset << "(" << reg_name[array_offset_reg] << ")" << std::endl;
        // Store in final destination
    } else {
        os << "sw " << reg_name[reg] << ", " << fp_offset << "(fp)" << std::endl;
    }
}

void Context::load_reg(std::ostream& os, int reg, int fp_offset) {
    // fp + fp_offset + array_offset_reg = address to target
    if (array_indexing) {
        os << "slli " << reg_name[array_offset_reg] << ", " << reg_name[array_offset_reg] << ", 2" << std::endl;
        // TODO replace this multiplication by 4 by something else to make it compatible with other types.
        // Convert array offset to byte addressing offset
        os << "add " << reg_name[array_offset_reg] << ", " << reg_name[array_offset_reg] << ", fp" << std::endl;
        // Add fp and array offset
        os << "lw " << reg_name[reg] << ", " << fp_offset << "(" << reg_name[array_offset_reg] << ")" << std::endl;
        // Store in final destination
    } else {
        os << "lw " << reg_name[reg] << ", " << fp_offset << "(fp)" << std::endl;
    }
}
