#include "ast/expressions/binary_expr/lt_expr.hpp"

LtExpr::LtExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value < r->value;
}

void LtExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    bool is_signed = left->is_signed && right->is_signed;
    os << (is_signed ? "slt " : "sltu ") << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    // TODO sltu
    os << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
    os << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;

    free(reg1, reg2, context);
}
