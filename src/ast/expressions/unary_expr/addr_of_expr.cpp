#include "ast/expressions/unary_expr/addr_of_expr.hpp"

AddrOfExpr::AddrOfExpr(Node* e) : UnaryOp(e) {}

void AddrOfExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    // TODO

}
