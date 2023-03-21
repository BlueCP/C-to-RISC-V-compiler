#pragma once

#include "unary_op.hpp"
#include "../binary_expr/assignment_expr.hpp"
#include "../binary_expr/sub_expr.hpp"
#include "../primary_expr.hpp"

class PreDecExpr : public UnaryOp {

public:

    PreDecExpr(Node* e);

    ~PreDecExpr();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* dec_expr;

};
