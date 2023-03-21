#include "ast/expressions/binary_expr/assignment_expr.hpp"

AssignmentExpr::AssignmentExpr(Node* l, Node* r) : BinaryOp(l, r) {}

void AssignmentExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    right->compile(os, dest_reg, context); // Evalutate expression to store
    context.storing_var = true; // To inform left.compile
    left->compile(os, dest_reg, context); // Store value in variable
    context.storing_var = false;
}
