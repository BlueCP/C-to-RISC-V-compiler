#pragma once

#include "unary_op.hpp"

class DerefExpr : public UnaryOp {

public:

    DerefExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
