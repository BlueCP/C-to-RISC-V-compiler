#include "ast/expressions/binary_expr/and_expr.hpp"

AndExpr::AndExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value & r->value;
}

void AndExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "and " << reg_name[dest_reg] << ", " << reg_name[reg1] <<  ", " << reg_name[reg2] << std::endl;
    free(reg1, reg2, context);
}
