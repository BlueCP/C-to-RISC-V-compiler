#pragma once

#include "../../node.hpp"

class WhileStatement : public Node {

public:

    WhileStatement(Node* c, Node* s);

    ~WhileStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* condition;
    Node* statement;

};
