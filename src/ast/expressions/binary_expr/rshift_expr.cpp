#include "ast/expressions/binary_expr/rshift_expr.hpp"

RshiftExpr::RshiftExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value >> r->value;
}

void RshiftExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "sra " << reg_name[dest_reg] << ", " << reg_name[reg1] << ", " << reg_name[reg2]  << std::endl;
    free(reg1, reg2, context);
}
