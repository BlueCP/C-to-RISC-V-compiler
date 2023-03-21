#pragma once

#include "binary_op.hpp"

class InclOrExpr : public BinaryOp {

public:

    InclOrExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
