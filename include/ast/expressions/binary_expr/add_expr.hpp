#pragma once

#include "binary_op.hpp"

class AddExpr : public BinaryOp {

public:

    AddExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
