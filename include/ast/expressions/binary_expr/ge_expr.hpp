#pragma once

#include "binary_op.hpp"

class GeExpr : public BinaryOp {

public:

    GeExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
