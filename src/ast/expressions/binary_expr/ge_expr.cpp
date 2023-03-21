#include "ast/expressions/binary_expr/ge_expr.hpp"

GeExpr::GeExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value >= r->value;
}

void GeExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "slt " << reg_name[reg1] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    os << "xori " << reg_name[reg1] << ", " << reg_name[reg1] << ", 1" << std::endl;
    os << "andi " << reg_name[reg1] << ", " << reg_name[reg1] << ", 0xff" << std::endl;
    os << "mv " << reg_name[dest_reg] << ", " << reg_name[reg1] << std::endl;


    free(reg1, reg2, context);
}
