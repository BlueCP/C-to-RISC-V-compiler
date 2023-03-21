#pragma once

#include "binary_op.hpp"

class LogicalOrExpr : public BinaryOp {

public:

    LogicalOrExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
