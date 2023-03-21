#include "ast/expressions/unary_expr/post_inc_expr.hpp"

PostIncExpr::PostIncExpr(Node* e) : UnaryOp(e) {
    value = e->value;
    inc_expr = new AssignmentExpr(e, new AddExpr(e, new Constant(1)));
}

PostIncExpr::~PostIncExpr() {
    delete inc_expr;
}

void PostIncExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    inc_expr->compile(os, dest_reg, context);
    os << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", -1" << std::endl;
    // Subtract 1 to negate the effect of the increment operation, so that dest_reg contains the original value.
}
