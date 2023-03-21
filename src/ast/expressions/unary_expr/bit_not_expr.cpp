#include "ast/expressions/unary_expr/bit_not_expr.hpp"

BitNotExpr::BitNotExpr(Node* e) : UnaryOp(e) {
    value = ~e->value;
}

void BitNotExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    expr->compile(os, dest_reg, context);
    os << "not " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
}
