#pragma once

#include "../../node.hpp"

class IfElseStatement : public Node {

public:

    IfElseStatement(Node* c, Node* s1, Node* s2);

    ~IfElseStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* condition;
    Node* if_stat;
    Node* else_stat;

};
