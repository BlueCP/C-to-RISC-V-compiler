#pragma once

#include "binary_op.hpp"

class LogicalAndExpr : public BinaryOp {

public:

    LogicalAndExpr(Node* l, Node* r) : BinaryOp(l, r) {
        value = l->value && r->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        auto [reg1, reg2] = eval(os, context);
        // TODO codegen

        std::string l2 = new_label("l2");
        std::string l3 = new_label("l3");

        std::cout << "beq " << reg_name[reg1] << ", 0, ." << l2 << std::endl;
        std::cout << "beq " << reg_name[reg2] << ", 0, ." << l2 << ":" << std::endl;

        std::cout << "li " << reg_name[dest_reg] << ", 1" << std::endl;
        std::cout << "j ." << l3 << std::endl;

        std::cout << "."<< l2 <<":" << std::endl;
        std::cout << "li " << reg_name[dest_reg] << ", 0" << std::endl;

        std::cout << "." << l3 << ":" << std::endl;

        free(reg1, reg2, context);
    }

};