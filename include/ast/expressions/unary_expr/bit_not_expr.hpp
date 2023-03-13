#pragma once

#include "unary_op.hpp"

class BitNotExpr : public UnaryOp {

public:

    BitNotExpr(Node* e) : UnaryOp(e) {
        value = ~e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        // TODO codegen 
        std::cout << "not " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
    }

};