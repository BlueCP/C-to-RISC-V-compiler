#include "ast/expressions/unary_expr/pre_inc_expr.hpp"

PreIncExpr::PreIncExpr(Node* e) : UnaryOp(e) {
    value = e->value + 1;
    inc_expr = new AssignmentExpr(e, new AddExpr(e, new Constant(1)));
}

PreIncExpr::~PreIncExpr() {
    delete inc_expr;
}

void PreIncExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    inc_expr->compile(os, dest_reg, context);
}
