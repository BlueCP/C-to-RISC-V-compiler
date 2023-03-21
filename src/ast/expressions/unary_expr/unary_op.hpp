#pragma once

#include "../../node.hpp"

class UnaryOp : public Node {

public:

    UnaryOp(Node* e) : expr(e) {}

    ~UnaryOp() {
        delete expr;
    }

    Node* expr;

};