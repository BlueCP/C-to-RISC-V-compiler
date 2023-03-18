#pragma once

#include "unary_op.hpp"

class PlusExpr : public UnaryOp {

public:

    PlusExpr(Node* e) : UnaryOp(e) {
        value = +e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        std::cout << "mv " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
    }

};