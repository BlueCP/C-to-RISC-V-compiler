#pragma once

#include "binary_op.hpp"

class LogicalOrExpr : public BinaryOp {

public:

    LogicalOrExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        // TODO codegen
        std::cout << "bne " << reg_name[reg1] << ", 0, .L2" << std::endl;
        std::cout << "beq " << reg_name[reg2] << ", 0, .L3" << std::endl;

        std::cout << ".L2:" << std::endl;
        std::cout << "li " << reg_name[dest_reg] << ", 1" << std::endl;
        std::cout << "l .L4" << std::endl;

        std::cout << ".L3:" << std::endl;
        std::cout << "li " << reg_name[dest_reg] << ", 0" << std::endl;

        std::cout << ".L4:" << std::endl;
        free(reg1, reg2, context);
    }

};