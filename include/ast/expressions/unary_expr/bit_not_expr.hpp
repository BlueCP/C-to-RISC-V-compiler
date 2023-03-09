#pragma once

#include "unary_op.hpp"

class BitNotExpr : public UnaryOp {

public:

    BitNotExpr(Node* e) : UnaryOp(e) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};