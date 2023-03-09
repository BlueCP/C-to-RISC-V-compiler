#pragma once

#include "../../node.hpp"

class WhileStatement : public Node {

public:

    WhileStatement(Node* c, Node* s) : condition(c), statement(s) {}

    ~WhileStatement() {
        delete condition;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

    Node* condition;
    Node* statement;

};