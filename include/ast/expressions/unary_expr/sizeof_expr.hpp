#pragma once

#include "unary_op.hpp"

class SizeofExpr : public UnaryOp {

public:

    SizeofExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
