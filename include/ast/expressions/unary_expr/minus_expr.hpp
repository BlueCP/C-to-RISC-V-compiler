#pragma once

#include "unary_op.hpp"

class MinusExpr : public UnaryOp {

public:

    MinusExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
