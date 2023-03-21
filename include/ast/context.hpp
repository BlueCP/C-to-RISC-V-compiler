#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include "utils.hpp"

class VarInfo {

public:

    VarInfo(int s, std::string i, int f);

    // std::string type;
    int size; // In bytes
    std::string identifier;
    int fp_offset; // Frame pointer offset

};

class Scope {

public:

    Scope(std::string i);

    ~Scope();

    // Add a new variable to the stack frame and return the fp offset.
    int new_variable(int size, std::string identifier);

    VarInfo* find_variable(std::string identifier);

    std::string identifier;
    std::vector<VarInfo*> variables;
    int fp_offset_tracker = -4; // Starts at -4 (the first available address in the stack frame)
                                // and decrements by some amount for each new variable, as far as needed.

};

class Context {

public:

    static const int STACK_FRAME_SIZE = 1024; // Equal to 256 words; move than enough.
        // Making the stack frame a constant size is a design choice; it is highly inefficient,
        // but simplifies implementation greatly.

    Context();

    ~Context();

    // Enter a new scope and create a stack frame.
    void new_scope(std::ostream& os, std::string identifier);

    // Leave the current scope and deallocate the stack frame.
    void leave_scope(std::ostream& os);

    bool in_global();

    // Returns the next available register. Useful for temporary results in calculations.
    // NOTE: Every get_reg should be matched with a free_reg.
    int get_reg();

    // Returns the next available register after having set it to zero.
    // NOTE: Every get_clean_reg should be matched with a free_reg.
    int get_clean_reg(std::ostream& os);

    // Marks a given register as available.
    void free_reg(int reg_id);

    // Prepares to create a new variable of given size in the current stack frame.
    // Returns the fp offset.
    int new_variable(int size, std::string identifier);

    // Returns the fp offset of a variable relative to the current fp.
    int find_fp_offset(std::string identifier);

    // Stores a register in the stack using the given fp offset.
    // Used for both initialising (with new_variable) and reassigning (with find_fp_offset).
    void store_reg(std::ostream& os, int reg, int fp_offset);

    // Loads a register from the stack using the given fp offset.
    // Used together with find_fp_offset.
    void load_reg(std::ostream& os, int reg, int fp_offset);

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
    std::string func_end_label;

};
