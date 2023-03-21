#pragma once

#include "../node.hpp"
#include "../node_list.hpp"

class FunctionCall : public Node {

public:

    FunctionCall(std::string i);

    FunctionCall(std::string i, NodeList* al);

    ~FunctionCall();

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

    NodeList* arg_list;

};
