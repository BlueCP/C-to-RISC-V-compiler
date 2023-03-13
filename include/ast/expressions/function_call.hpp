#pragma once

#include "../node.hpp"
#include "../node_list.hpp"

class FunctionCall : public Node {

public:

    FunctionCall(std::string i) : Node(i) {}

    FunctionCall(std::string i, NodeList* al) : Node(i), arg_list(al) {}

    ~FunctionCall() {
        delete arg_list;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        for (int i = 0; i < arg_list->node_list.size(); i++) {
            arg_list->node_list[i]->compile(os, 10 + i, context); // Load argument registers
        }
        // TODO codegen call function.
        std::cout << "call " << identifier << std::endl;
    }

    NodeList* arg_list;
    
};