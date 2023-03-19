#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/add_expr.hpp"
#include "../primary_expr.hpp"

class PostIncExpr : public UnaryOp {

public:

    PostIncExpr(Node* e) : UnaryOp(e) {
        value = e->value;
        inc_expr = new AssignmentExpr(e, new AddExpr(e, new Constant(1)));
    }

    ~PostIncExpr() {
        delete inc_expr;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        inc_expr->compile(os, dest_reg, context);
        std::cout << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ", -1" << std::endl;
        // Subtract 1 to negate the effect of the increment operation, so that dest_reg contains the original value.
    }

    Node* inc_expr;

};