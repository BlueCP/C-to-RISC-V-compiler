#include "ast/expressions/unary_expr/plus_expr.hpp"

PlusExpr::PlusExpr(Node* e) : UnaryOp(e) {
    value = +e->value;
}

void PlusExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    expr->compile(os, dest_reg, context);
    os << "mv " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
}
