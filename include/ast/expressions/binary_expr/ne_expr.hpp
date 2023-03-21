#pragma once

#include "binary_op.hpp"

class NeExpr : public BinaryOp {

public:

    NeExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
