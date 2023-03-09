#pragma once

#include "../../node.hpp"

class IfStatement : public Node {

public:

    IfStatement(Node* c, Node* s) : condition(c), statement(s) {}

    ~IfStatement() {
        delete condition;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

    Node* condition;
    Node* statement;

};