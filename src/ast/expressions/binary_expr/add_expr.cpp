#include "ast/expressions/binary_expr/add_expr.hpp"

AddExpr::AddExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value + l->value;
}

void AddExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);
    os << "add " << reg_name[dest_reg] << ", " << reg_name[reg1] << ", " << reg_name[reg2] << std::endl;
    free(reg1, reg2, context);
}
