#include "ast/expressions/function_call.hpp"

FunctionCall::FunctionCall(std::string i) : Node(i), arg_list(nullptr) {}

FunctionCall::FunctionCall(std::string i, NodeList* al) : Node(i), arg_list(al) {}

FunctionCall::~FunctionCall() {
    if (arg_list != nullptr) {
        delete arg_list;
    }
}

void FunctionCall::compile(std::ostream& os, int dest_reg, Context& context) const {
    // Save all temporary registers and argument registers before calling.
    // This is so that functions like (a + b) + f(1) do not fail because a and b were kept in temporary/argument registers.
    // This is an inefficient solution, and ideally we would check the expression tree to see if there are any
    // function calls, and if so, do not keep operands in temporary/argument registers. However, this solution is easier.

    // Note that we do not save the return register, a0.
    for (int i = 0; i < 7; i++) {
        os << "sw t" << i << ", " << 52 + 4*i << "(sp)" << std::endl; // Temporary registers
    }
    for (int i = 1; i < 8; i++) {
        os << "sw a" << i << ", " << 80 + 4*i << "(sp)" << std::endl; // Argument registers
    }


    if (arg_list != nullptr) { // If the function has arguments
        for (unsigned i = 0; i < arg_list->node_list.size(); i++) {
            arg_list->node_list[i]->compile(os, 10 + i, context); // Load argument registers
        }
    }

    os << "call " << identifier << std::endl;

    // Restore temporary and argument registers.
    for (int i = 0; i < 7; i++) {
        os << "lw t" << i << ", " << 52 + 4*i << "(sp)" << std::endl; // Temporary registers
    }
    for (int i = 1; i < 8; i++) {
        os << "lw a" << i << ", " << 80 + 4*i << "(sp)" << std::endl; // Argument registers
    }

    os << "mv " << reg_name[dest_reg] << ", a0" << std::endl;
    // Move the result of the function call (in a0) into dest_reg.
}
