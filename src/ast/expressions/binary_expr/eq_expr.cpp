#include "ast/expressions/binary_expr/eq_expr.hpp"

EqExpr::EqExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value == r->value;
}

void EqExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "sub " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    os << "seqz " << reg_name[reg1] << ", " << reg_name[reg1] << std::endl;
    os << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
    os << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;

    free(reg1, reg2, context);
}
