#pragma once

#include "../../node.hpp"

class IfElseStatement : public Node {

public:

    IfElseStatement(Node* c, Node* s1, Node* s2) : condition(c), if_stat(s1), else_stat(s2) {}

    ~IfElseStatement() {
        delete condition;
        delete if_stat;
        delete else_stat;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen
    }

    Node* condition;
    Node* if_stat;
    Node* else_stat;

};