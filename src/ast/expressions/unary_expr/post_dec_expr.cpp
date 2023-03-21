#include "ast/expressions/unary_expr/post_dec_expr.hpp"

PostDecExpr::PostDecExpr(Node* e) : UnaryOp(e) {
    value = e->value;
    dec_expr = new AssignmentExpr(e, new SubExpr(e, new Constant(1)));
}

PostDecExpr::~PostDecExpr() {
    delete dec_expr;
}

void PostDecExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    dec_expr->compile(os, dest_reg, context);
    os << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", 1" << std::endl;
    // Add 1 to negate the effect of the decrement operation, so that dest_reg contains the original value.
}
