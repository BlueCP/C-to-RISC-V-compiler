#pragma once

#include "binary_op.hpp"

class ModExpr : public BinaryOp {

public:

    ModExpr(Node* l, Node* r);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
