#pragma once

#include "unary_op.hpp"

class NotExpr : public UnaryOp {

public:

    NotExpr(Node* e);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
