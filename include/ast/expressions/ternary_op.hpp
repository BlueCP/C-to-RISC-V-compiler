#pragma once

#include "../node.hpp"
#include "../statements/selection_statements/if_else_statement.hpp"

// As far as I can see, a ternary statement is essentially the same as an
// if-else statement in the view of codegen.

class TernaryOp : public IfElseStatement {

public:

    TernaryOp(Node* c, Node* i, Node* e) : IfElseStatement(c, i, e) {}

};
