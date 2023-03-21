#include "ast/expressions/binary_expr/logical_and_expr.hpp"

LogicalAndExpr::LogicalAndExpr(Node* l, Node* r) : BinaryOp(l, r) {
    value = l->value && r->value;
}

void LogicalAndExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto [reg1, reg2] = eval(os, context);

    std::string l2 = new_label("l2");
    std::string l3 = new_label("l3");

    os << "beq " << reg_name[reg1] << ", zero, ." << l2 << std::endl;
    os << "beq " << reg_name[reg2] << ", zero, ." << l2 << std::endl;

    os << "li " << reg_name[dest_reg] << ", 1" << std::endl;
    os << "j ." << l3 << std::endl;

    os << "."<< l2 <<":" << std::endl;
    os << "li " << reg_name[dest_reg] << ", 0" << std::endl;

    os << "." << l3 << ":" << std::endl;

    free(reg1, reg2, context);
}
