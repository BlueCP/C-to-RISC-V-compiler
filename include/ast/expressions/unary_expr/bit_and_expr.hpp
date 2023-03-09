#pragma once

#include "unary_op.hpp"

class BitAndExpr : public UnaryOp {

public:

    BitAndExpr(Node* e) : UnaryOp(e) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};