#include "ast/expressions/binary_expr/le_expr.hpp"

LeExpr::LeExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value <= r->value;
}

void LeExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    bool is_signed = left->is_signed && right->is_signed;
    os << (is_signed ? "sgt " : "sgtu ") << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    // TODO sgtu
    os << "xori " << reg_name[reg1] << ", " << reg_name[reg1] << ", 1" << std::endl;
    os << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
    os << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;
    free(reg1, reg2, context);
}

