#pragma once

#include "../../node.hpp"

class ReturnStatement : public Node {

public:

    ReturnStatement(Node* _e) : expression(_e) {}

    ReturnStatement() : expression(nullptr) {}

    ~ReturnStatement() {
        if (expression != nullptr) {
            delete expression;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
        // Note that if expression is nullptr, there is no value to be returned.
    }

    Node* expression;

};