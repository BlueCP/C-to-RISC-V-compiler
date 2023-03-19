#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/sub_expr.hpp"
#include "../primary_expr.hpp"

class PostDecExpr : public UnaryOp {

public:

    PostDecExpr(Node* e) : UnaryOp(e) {
        value = e->value;
        dec_expr = new AssignmentExpr(e, new SubExpr(e, new Constant(1)));
    }

    ~PostDecExpr() {
        delete dec_expr;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        dec_expr->compile(os, dest_reg, context);
        std::cout << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", 1" << std::endl;
        // Add 1 to negate the effect of the decrement operation, so that dest_reg contains the original value.
    }

    Node* dec_expr;

};