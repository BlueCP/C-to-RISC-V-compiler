#pragma once

#include "unary_op.hpp"

class MinusExpr : public UnaryOp {

public:

    MinusExpr(Node* e) : UnaryOp(e) {
        value = -e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        os << "neg " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
    }

};
