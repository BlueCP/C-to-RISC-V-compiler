#include "ast/expressions/ternary_op.hpp"

// As far as I can see, a ternary statement is essentially the same as an
// if-else statement in the view of codegen.

TernaryOp::TernaryOp(Node* c, Node* i, Node* e) : IfElseStatement(c, i, e) {}
