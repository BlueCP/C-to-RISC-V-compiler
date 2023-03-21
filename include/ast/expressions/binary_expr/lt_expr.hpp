#pragma once

#include "binary_op.hpp"

class LtExpr : public BinaryOp {

public:

    LtExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
