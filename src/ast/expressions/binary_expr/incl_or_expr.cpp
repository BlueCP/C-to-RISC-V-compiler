#include "ast/expressions/binary_expr/incl_or_expr.hpp"

InclOrExpr::InclOrExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value | r->value;
}

void InclOrExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "or " << reg_name[dest_reg] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    free(reg1, reg2, context);
}
