#include "ast/expressions/unary_expr/addr_of_expr.hpp"

AddrOfExpr::AddrOfExpr(Node *e) : UnaryOp(e) {}

void AddrOfExpr::compile(std::ostream &os, int dest_reg, Context &context) const
{
    // TODO
    if (1 /*global*/)
    {
        os << "lui " << reg_name[dest_reg] << ", %hi(" << expr->identifier << ")" << std::endl;
        os << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ",%lo(" << expr->identifier << ")" << std::endl;
    }
    else
    {
        int offset = context.find_fp_offset(expr->identifier);
        os << "addi " << reg_name[dest_reg] << ", fp, -" << offset << std::endl;
    }
}
