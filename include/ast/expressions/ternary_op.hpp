#pragma once

#include "../node.hpp"

class TernaryOp : public Node {

public:

    TernaryOp(Node* c, Node* e1, Node* e2)
        : condition(c), expr1(e1), expr2(e2) {

    }

    ~TernaryOp() {
        delete condition;
        delete expr1;
        delete expr2;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: variable assignment.
    }

    Node* condition;
    Node* expr1;
    Node* expr2;

};