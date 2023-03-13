#pragma once

#include "unary_op.hpp"

class PostIncExpr : public UnaryOp {

public:

    PostIncExpr(Node* e) : UnaryOp(e) {
        value = e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
        //do smth
        std::cout << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", 1" << std::endl;


    }

};