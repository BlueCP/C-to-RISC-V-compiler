#include "ast/expressions/unary_expr/minus_expr.hpp"

MinusExpr::MinusExpr(Node* e) : UnaryOp(e) {
    value = -e->value;
}

void MinusExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    expr->compile(os, dest_reg, context);
    os << "neg " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
}
