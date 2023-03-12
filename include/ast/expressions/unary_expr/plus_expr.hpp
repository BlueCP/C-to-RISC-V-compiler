#pragma once

#include "unary_op.hpp"

class PlusExpr : public UnaryOp {

public:

    PlusExpr(Node* e) : UnaryOp(e) {
        value = +e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        // TODO codegen
    }

};