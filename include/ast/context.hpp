#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include "utils.hpp"

class VarInfo {

public:

    VarInfo(int s, bool is, std::string i, int f);

    // std::string type;
    int size; // In bytes
    bool is_signed;
    std::string identifier;
    int fp_offset; // Frame pointer offset (for global variables this is just set to 0)

};

class Scope {

public:

    Scope();

    ~Scope();

    // Add a new variable add return the scope offset.
    int new_variable(int size, bool is_signed, std::string identifier, int frame_offset);

    // Find a variable with the given identifier.
    VarInfo* find_variable(std::string identifier);

    std::vector<VarInfo*> variables;
    int scope_offset = 0; // Total fp offset = frame offset + scope offset.

};

class Frame {

public:

    Frame();

    ~Frame();

    // Create a new scope.
    void new_scope();

    // Leave the scope.
    void leave_scope();

    // Add a new variable to the stack frame and return the fp offset.
    int new_variable(int size, bool is_signed, std::string identifier);

    VarInfo* find_variable(std::string identifier);

    std::vector<Scope*> scope_stack;
    int frame_offset = 0; // Starts at -4 after decrementing (the first available address in the stack frame)
                          // and decrements by some amount for each new variable, as far as needed.

};

class Context {

public:

    static const int STACK_FRAME_SIZE = 1024; // Equal to 256 words; move than enough.
        // Making the stack frame a constant size is a design choice; it is highly inefficient,
        // but simplifies implementation greatly.

    Context();

    ~Context();

    // Create a new stack frame and enter it.
    void new_frame(std::ostream& os);

    // Deallocate the current stack frame.
    void leave_frame(std::ostream& os);

    // Create a new scope.
    void new_scope();

    // Leave the current scope.
    void leave_scope();

    // Prepares to create a new variable of given size in the current stack frame.
    // Returns the fp offset.
    int new_variable(int size, bool is_signed, std::string identifier);

    bool in_global();

    // Returns the next available register. Useful for temporary results in calculations.
    // NOTE: Every get_reg should be matched with a free_reg.
    int get_reg();

    // Returns the next available register after having set it to zero.
    // NOTE: Every get_clean_reg should be matched with a free_reg.
    int get_clean_reg(std::ostream& os);

    // Marks a given register as available.
    void free_reg(int reg_id);

    // Finds information about a local variable.
    VarInfo* find_local_var(std::string identifier);

    // Returns variable information if a global variable with the given identifer exists.
    // Otherwise, returns nullptr.
    VarInfo* find_global_var(std::string identifier);

    // Returns the fp offset of a variable relative to the current fp.
    int find_fp_offset(std::string identifier);

    // Stores a register in the stack using the given fp offset.
    // Used for both initialising (with new_variable) and reassigning (with find_fp_offset).
    void store_reg(std::ostream& os, int reg, int fp_offset, bool is_byte);

    // Loads a register from the stack using the given fp offset.
    // Used together with find_fp_offset.
    void load_reg(std::ostream& os, int reg, int fp_offset, bool is_byte);

    std::vector<VarInfo*> global_variables; // A list of global variables.

    std::map<std::string, int> enum_map;
    // A mapping between the names of enum elements and their values.
    // We are assuming global scope for enums, and no differentiation based on their identifiers.
    int enum_counter = 0;

    int array_size = 0; // Number of elements in the array currently being declared.

    std::vector<Frame*> frame_stack;
    bool reg_available[32] = {0, 0, 0, 0, 0, 1, 1, 1,
                              0, 1, 0, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1};
        // Aside from first 5 registers, mark a0 and fp as unavailable.

    bool function_declarator_start = true; // Are we are the header or footer of a function definition?
    bool storing_var = false; // Are we storing an expression, rather than reading it into dest_reg?
    int array_offset_reg = 0; // Register containing array offset, zero by default (no offset).
    bool array_indexing = false; // Whether or not we are currently indexing an array.
    std::string continue_label;
    std::string break_label;
    int switch_cascade_reg = 0;
    std::string func_end_label;
    bool function_def = false; // Whether or not we are currently defining (as opposed to declaring) a function.
    bool case_headers = false; // Whether we are generating the headers or footers of case statements.
                               // We default to false because if case_headers is true, we have special behaviour
                               // in node_list.
    int case_index = 0;
    std::vector<std::string> case_labels;

};
