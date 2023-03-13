#pragma once

#include "unary_op.hpp"

class PreDecExpr : public UnaryOp {

public:

    PreDecExpr(Node* e) : UnaryOp(e) {
        value = e->value - 1;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
        std::cout << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", -1" << std::endl;
        //do smth

    }

};