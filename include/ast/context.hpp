#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>

class Context {

public:

    static const int STACK_FRAME_SIZE = 1024; // Equal to 256 words; move than enough.
        // Making the stack frame a constant size is a design choice; it is highly inefficient,
        // but simplifies implementation greatly.

    Context() {}

    ~Context() {
        for (auto s : scope_stack) {
            delete s;
        }
    }

    // Enter a new scope and create a stack frame.
    void new_scope(std::ostream& os, std::string identifier) {
        scope_stack.push_back(new Scope(identifier));
        // TODO codgen
        // 1. Move the stack pointer down (by STACK_FRAME_SIZE).
        // 2. Push the frame pointer to the stack.
        // 3. Move the frame pointer up (to the bottom of the previous stack frame).
    }

    // Leave the current scope and deallocate the stack frame.
    void leave_scope(std::ostream& os) {
        delete scope_stack.back();
        scope_stack.pop_back();
        // TODO codgen
        // 1. Load the frame pointer from the stack.
        // 2. Move the stack pointer up to deallocate the stack frame.
    }

    // Returns the next available register.
    int get_reg() {
        for (int i = 0; i < 32; i++) {
            if (reg_available[i]) {
                reg_available[i] = false;
                return i;
            }
        }
        return -1; // In future expand on this function to avoid this happening (somehow).
    }

    // Marks a given register as available.
    void free_reg(int reg_id) {
        reg_available[reg_id] = true;
    }

    // Creates a new variable in the current stack frame.
    // Returns the fp offset.
    int new_variable(std::string type, std::string identifier) {
        return scope_stack.back()->new_variable(type, identifier);
    }

    // Stores a register in the stack using the given fp offset.
    void store_reg(std::ostream& os, int reg, int fp_offset) {
        // TODO codegen
    }

    // Returns the fp offset of a variable relative to the current fp.
    int find_fp_offset(std::string identifier) {
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
            // Since fp_offset is relevant to the variable's own stack frame, not the current one,
            // we have to readjust it by using how many frames deep we have to go.
        }
    }

    // Loads a register from the stack using the given fp offset.
    void load_reg(std::ostream& os, int reg, int fp_offset) {
        // TODO codegen
    }

    std::vector<Scope*> scope_stack;
    bool reg_available[32] = {0, 0, 0, 0, 0, 1, 1, 1,
                              1, 1, 0, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1};
        // Aside from first 5 registers, mark a0 (return value register) as unavailable just in case.

    bool function_declarator_start;
    bool return_flag;

};

class Scope {

public:

    Scope(std::string i) : identifier(i) {}

    ~Scope() {
        for (auto v : variables) {
            delete v;
        }
    }

    // Add a new variable to the stack frame and return the fp offset.
    int new_variable(std::string type, std::string identifier) {
        variables.push_back(new VarInfo(type, identifier, fp_offset_tracker - 4));
        fp_offset_tracker -= 4;
        return fp_offset_tracker;
        // If the fp_offset_tracker exceeds the stack frame size, the program will have undefined behaviour.
    }

    VarInfo* find_variable(std::string identifier) {
        for (auto v : variables) {
            if (v->identifier == identifier) {
                return v;
            }
        }
        return nullptr;
    }

    std::string identifier;
    std::vector<VarInfo*> variables;
    int fp_offset_tracker = -4; // Starts at -4 (the first available address in the stack frame)
                                // and decrements by -4 for each new variable, as far as needed.

};

class VarInfo {

public:

    VarInfo(std::string t, std::string i, int f)
        : type(t), identifier(i), fp_offset(f) {}

    std::string type;
    std::string identifier;
    int fp_offset; // Frame pointer offset

};