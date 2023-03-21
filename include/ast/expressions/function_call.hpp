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

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) {
        // Function call is independent of dest_reg.
        for (unsigned i = 0; i < arg_list->node_list.size(); i++) {
            arg_list->node_list[i]->compile(os, 10 + i, context); // Load argument registers
        }
        os << "call " << identifier << std::endl;
    }

    NodeList* arg_list;

};
