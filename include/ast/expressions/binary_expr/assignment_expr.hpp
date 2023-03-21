#pragma once

#include "binary_op.hpp"

// Note: AssignmentExpr does not follow the same pattern as all other binary
// expressions, since the left and right-hand sides have different meanings.
class AssignmentExpr : public BinaryOp {

public:

    AssignmentExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
