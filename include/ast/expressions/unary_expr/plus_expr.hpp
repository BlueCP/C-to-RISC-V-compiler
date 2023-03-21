#pragma once

#include "unary_op.hpp"

class PlusExpr : public UnaryOp {

public:

    PlusExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
