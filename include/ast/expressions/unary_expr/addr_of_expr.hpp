#pragma once

#include "unary_op.hpp"

class AddrOfExpr : public UnaryOp {

public:

    AddrOfExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
