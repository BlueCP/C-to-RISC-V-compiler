#pragma once

#include "unary_op.hpp"

class PostIncExpr : public UnaryOp {

public:

    PostIncExpr(Node* e) : UnaryOp(e) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

};