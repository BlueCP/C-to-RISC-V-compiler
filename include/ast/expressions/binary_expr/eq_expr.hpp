#pragma once

#include "binary_op.hpp"

class EqExpr : public BinaryOp {

public:

    EqExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
