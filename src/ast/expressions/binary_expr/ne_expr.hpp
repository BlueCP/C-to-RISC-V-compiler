#pragma once

#include "binary_op.hpp"

class NeExpr : public BinaryOp {

public:

    NeExpr(Node* l, Node* r) : BinaryOp(l, r) {
        value = l->value != r->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        os << "sub " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
        os << "snez " << reg_name[reg1] << ", " << reg_name[reg1] << std::endl;
        os << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
        os << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;
        free(reg1, reg2, context);
    }

};
