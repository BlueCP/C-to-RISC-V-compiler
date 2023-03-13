#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include "node.hpp"

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
        std::cout << "addi sp, sp, -" << STACK_FRAME_SIZE << std::endl;
        // 2. Push the return address to the stack.
        //   - this is redunant in most cases, but it simplifes implementation to
        //     just do it every time.
        std::cout << "sw ra, 0(sp)" << std::endl;

        // 3. Push the frame pointer to the stack.
        std::cout << "sw fp, 4(sp)" << std::endl;

        // 4. Move the frame pointer up (to the bottom of the previous stack frame).
        std::cout << "addi fp, sp, " << STACK_FRAME_SIZE << std::endl; 
    }

    // Leave the current scope and deallocate the stack frame.
    void leave_scope(std::ostream& os) {
        delete scope_stack.back();
        scope_stack.pop_back();
        // TODO codgen
        // 1. Load the return address from the stack.
        std::cout << "lw ra, 0(sp)" << std::endl;
        // 2. Load the frame pointer from the stack.
        std::cout << "lw fp, 4(sp)" << std::endl;
        // 3. Move the stack pointer up to deallocate the stack frame.
        std::cout << "addi sp, sp, " << STACK_FRAME_SIZE << std::endl;
    }

    bool in_global() {
        return scope_stack.size() == 0;
        // Being in global scope is equivalent to there not being any stack frames (I think)
    }

    // Returns the next available register. Useful for temporary results in calculations.
    // NOTE: Every get_reg should be matched with a free_reg.
    int get_reg() {
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
    int get_clean_reg(std::ostream& os) {
        int reg = get_reg();
        // TODO codegen set this reg to 0.
        std::cout << "addi, " << reg_name[reg] << ", zero, 0" << std::endl;
        return reg;
    }

    // Marks a given register as available.
    void free_reg(int reg_id) {
        reg_available[reg_id] = true;
    }

    // Prepares to create a new variable of given size in the current stack frame.
    // Returns the fp offset.
    int new_variable(int size, std::string identifier) {
        return scope_stack.back()->new_variable(size, identifier);
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
            // Since fp_offset is relative to the variable's own stack frame, not the current one,
            // we have to readjust it by counting how many frames deep we have to go.
        }
    }

    // Stores a register in the stack using the given fp offset.
    // Used for both initialising (with new_variable) and reassigning (with find_fp_offset).
    void store_reg(std::ostream& os, int reg, int fp_offset) {
        // TODO codegen
        // fp + fp_offset + array_offset_reg = address to target
        std::cout << "sw " << reg_name[reg] <<  ", fp(" << fp_offset + array_offset_reg << ")" << std::endl;
    }

    // Loads a register from the stack using the given fp offset.
    // Used together with find_fp_offset.
    void load_reg(std::ostream& os, int reg, int fp_offset) {
        // TODO codegen
        // fp + fp_offset + array_offset_reg = address to target
        std::cout << "lw " << reg_name[reg] << ", fp(" << fp_offset + array_offset_reg << ")" << std::endl;
    }

    std::map<std::string, int> enum_map;
    // A mapping between the names of enum elements and their values.
    // We are assuming global scope for enums, and no differentiation based on their identifiers.
    int enum_counter = 0;

    int array_size = 0; // Number of elements in the array currently being declared.

    std::vector<Scope*> scope_stack;
    bool reg_available[32] = {0, 0, 0, 0, 0, 1, 1, 1,
                              1, 1, 0, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1};
        // Aside from first 5 registers, mark a0 (return value register) as unavailable just in case.

    bool function_declarator_start = true; // Are we are the header or footer of a function definition?
    bool return_flag = false; // Have we just reached a return statement, thus ending the compilation of statements prematurely?
    bool storing_var = false; // Are we storing an expression, rather than reading it into dest_reg?
    int array_offset_reg = 0; // Register containing array offset, zero by default (no offset).
    std::string continue_label;
    std::string break_label;
    int switch_cascade_reg = 0;

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
    int new_variable(int size, std::string identifier) {
        fp_offset_tracker -= size;
        variables.push_back(new VarInfo(size, identifier, fp_offset_tracker));
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
                                // and decrements by some amount for each new variable, as far as needed.

};

class VarInfo {

public:

    VarInfo(int s, std::string i, int f)
        : size(s), identifier(i), fp_offset(f) {}

    // std::string type;
    int size; // In bytes
    std::string identifier;
    int fp_offset; // Frame pointer offset

};