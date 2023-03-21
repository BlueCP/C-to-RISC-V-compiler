#include "ast/expressions/function_call.hpp"

FunctionCall::FunctionCall(std::string i) : Node(i) {}

FunctionCall::FunctionCall(std::string i, NodeList* al) : Node(i), arg_list(al) {}

FunctionCall::~FunctionCall() {
    delete arg_list;
}

void FunctionCall::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    // Function call is independent of dest_reg.
    for (unsigned i = 0; i < arg_list->node_list.size(); i++) {
        arg_list->node_list[i]->compile(os, 10 + i, context); // Load argument registers
    }
    os << "call " << identifier << std::endl;
}
