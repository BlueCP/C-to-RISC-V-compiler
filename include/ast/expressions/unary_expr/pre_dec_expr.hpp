#pragma once

#include "unary_op.hpp"

class PreDecExpr : public UnaryOp {

public:

    PreDecExpr(Node* e) : UnaryOp(e) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};