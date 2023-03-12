#pragma once

#include "../../node.hpp"

class DefaultStatement : public Node {

public:

    DefaultStatement(Node* s) : statement(s) {}

    ~DefaultStatement() {
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        // TODO codegen execute statement if context.switch_cascade_reg is 0.
    }

    Node* statement;

};