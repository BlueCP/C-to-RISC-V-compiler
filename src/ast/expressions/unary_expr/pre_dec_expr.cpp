#include "ast/expressions/unary_expr/pre_dec_expr.hpp"

PreDecExpr::PreDecExpr(Node* e) : UnaryOp(e) {
    value = e->value - 1;
    dec_expr = new AssignmentExpr(e, new SubExpr(e, new Constant(1)));
}

PreDecExpr::~PreDecExpr() {
    delete dec_expr;
}

void PreDecExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    dec_expr->compile(os, dest_reg, context);
}
