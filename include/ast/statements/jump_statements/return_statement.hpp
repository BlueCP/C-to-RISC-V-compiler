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
        if (expression != nullptr) {
            expression->compile(os, dest_reg, context);
        }
        context.return_flag = true;
    }

    Node* expression;

};