#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/sub_expr.hpp"
#include "../primary_expr.hpp"

class PreDecExpr : public UnaryOp {

public:

    PreDecExpr(Node* e) : UnaryOp(e) {
        value = e->value - 1;
        dec_expr = new AssignmentExpr(e, new SubExpr(e, new Constant(1)));
    }

    ~PreDecExpr() {
        delete dec_expr;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        dec_expr->compile(os, dest_reg, context);
    }

    Node* dec_expr;

};