#include "ast/expressions/binary_expr/mod_expr.hpp"

ModExpr::ModExpr(Node* l, Node* r) : BinaryOp(l, r) {
    if (r->value != 0) {
        value = l->value % r->value;
    }
}

void ModExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    bool is_signed = left->is_signed && right->is_signed;
    os << (is_signed ? "rem " : "remu ") << reg_name[dest_reg] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    free(reg1, reg2, context);
}
