#pragma once

#include "binary_op.hpp"

class LtExpr : public BinaryOp {

public:

    LtExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        // TODO codegen
        std::cout << "slt " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
        std::cout << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << std::endl;
        std::cout << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;

        free(reg1, reg2, context);
    }

};