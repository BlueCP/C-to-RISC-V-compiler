#pragma once

#include "binary_op.hpp"

class ExclOrExpr : public BinaryOp {

public:

    ExclOrExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
