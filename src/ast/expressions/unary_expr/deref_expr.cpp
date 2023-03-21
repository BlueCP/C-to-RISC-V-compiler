#include "ast/expressions/unary_expr/deref_expr.hpp"

DerefExpr::DerefExpr(Node* e) : UnaryOp(e) {}

void DerefExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    // TODO
}
