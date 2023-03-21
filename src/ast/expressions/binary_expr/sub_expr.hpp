#pragma once

#include "binary_op.hpp"

class SubExpr : public BinaryOp {

public:

    SubExpr(Node* l, Node* r) : BinaryOp(l, r) {
        value = l->value - r->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        os << "sub " << reg_name[dest_reg] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
        free(reg1, reg2, context);
    }

};
