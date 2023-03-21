#include "ast/expressions/unary_expr/unary_op.hpp"

UnaryOp::UnaryOp(Node* e) : expr(e) {}

UnaryOp::~UnaryOp() {
    delete expr;
}
