#pragma once

#include "binary_op.hpp"

class LeExpr : public BinaryOp {

public:

    LeExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
