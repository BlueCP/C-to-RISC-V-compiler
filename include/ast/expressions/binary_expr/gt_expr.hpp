#pragma once

#include "binary_op.hpp"

class GtExpr : public BinaryOp {

public:

    GtExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};