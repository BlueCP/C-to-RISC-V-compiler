#pragma once

#include "../../node.hpp"

class DefaultStatement : public Node {

public:

    DefaultStatement(Node* s) : statement(s) {}

    ~DefaultStatement() {
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen execute statement if context.switch_cascade_reg is 0.
        auto l1 = new_label("l1");

        os << "bne " << reg_name[context.switch_cascade_reg] << ", 0, ." << l1 << std::endl;
        statement->compile(os, dest_reg, context);
        os << "." << l1 << ":" << std::endl;

    }

    Node* statement;

};
