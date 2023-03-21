#pragma once

#include "binary_op.hpp"

// Note: AssignmentExpr does not follow the same pattern as all other binary
// expressions, since the left and right-hand sides have different meanings.
class AssignmentExpr : public BinaryOp {

public:

    AssignmentExpr(Node* l, Node* r) : BinaryOp(l, r) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        right->compile(os, dest_reg, context); // Evalutate expression to store
        context.storing_var = true; // To inform left.compile
        left->compile(os, dest_reg, context); // Store value in variable
        context.storing_var = false;
    }

};