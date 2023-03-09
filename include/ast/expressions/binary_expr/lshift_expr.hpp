#pragma once

#include "binary_op.hpp"

class LshiftExpr : public BinaryOp {

public:

    LshiftExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};