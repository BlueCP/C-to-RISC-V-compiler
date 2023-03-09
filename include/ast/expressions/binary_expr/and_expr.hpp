#pragma once

#include "binary_op.hpp"

class AndExpr : public BinaryOp {

public:

    AndExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};