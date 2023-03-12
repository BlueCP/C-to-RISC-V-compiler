#pragma once

#include "binary_op.hpp"

class EqExpr : public BinaryOp {

public:

    EqExpr(Node* l, Node* r) : BinaryOp(l, r) {
        value = l->value == r->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        // TODO codegen
        free(reg1, reg2, context);
    }

};