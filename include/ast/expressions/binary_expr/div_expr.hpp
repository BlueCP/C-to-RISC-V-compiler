#pragma once

#include "binary_op.hpp"

class DivExpr : public BinaryOp {

public:

    DivExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
