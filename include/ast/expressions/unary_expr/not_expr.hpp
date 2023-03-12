#pragma once

#include "unary_op.hpp"

class NotExpr : public UnaryOp {

public:

    NotExpr(Node* e) : UnaryOp(e) {
        value = !e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        expr->compile(os, dest_reg, context);
        // TODO codegen
        std::cout << "seqz " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
        std::cout << "andi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", 0xff" << std::endl;
    }

};