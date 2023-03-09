#pragma once

#include "node.hpp"

class ReturnStatement : public Node {

public:

    ReturnStatement(Node* _e)
        : expression(_e) {

    }

    ~ReturnStatement() {
        delete expression;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

private:

    Node* expression;

};