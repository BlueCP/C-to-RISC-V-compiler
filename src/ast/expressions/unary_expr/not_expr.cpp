#include "ast/expressions/unary_expr/not_expr.hpp"

NotExpr::NotExpr(Node* e) : UnaryOp(e) {
    value = !e->value;
}

void NotExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    expr->compile(os, dest_reg, context);
    os << "seqz " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << std::endl;
    os << "andi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", 0xff" << std::endl;
}
