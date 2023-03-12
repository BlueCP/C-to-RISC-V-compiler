#pragma once

#include "unary_op.hpp"

class PostDecExpr : public UnaryOp {

public:

    PostDecExpr(Node* e) : UnaryOp(e) {
        value = e->value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};