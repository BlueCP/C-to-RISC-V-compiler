#pragma once

#include "binary_op.hpp"

class AssignmentExpr : public BinaryOp {

public:

    AssignmentExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};