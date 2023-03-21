#pragma once

#include "../../node.hpp"

class IfStatement : public Node {

public:

    IfStatement(Node* c, Node* s);

    ~IfStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* condition;
    Node* statement;

};
