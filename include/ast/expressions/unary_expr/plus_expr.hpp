#pragma once

#include "unary_op.hpp"

class PlusExpr : public UnaryOp {

public:

    PlusExpr(Node* e) : UnaryOp(e) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        // TODO codegen
        std::cout << "mv " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
    }

};