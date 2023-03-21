#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/add_expr.hpp"
#include "../primary_expr.hpp"

class PostIncExpr : public UnaryOp {

public:

    PostIncExpr(Node* e);

    ~PostIncExpr();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* inc_expr;

};
