#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/add_expr.hpp"
#include "../primary_expr.hpp"

class PreIncExpr : public UnaryOp {

public:

    PreIncExpr(Node* e) : UnaryOp(e) {
        value = e->value + 1;
        inc_expr = new AssignmentExpr(e, new AddExpr(e, new Constant(1)));
    }

    ~PreIncExpr() {
        delete inc_expr;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        inc_expr->compile(os, dest_reg, context);
    }

    Node* inc_expr;

};