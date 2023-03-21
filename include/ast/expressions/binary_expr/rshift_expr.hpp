#pragma once

#include "binary_op.hpp"

class RshiftExpr : public BinaryOp {

public:

    RshiftExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
