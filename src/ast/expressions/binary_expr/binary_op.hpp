#pragma once

#include "../../node.hpp"

class BinaryOp : public Node {

public:

    BinaryOp(Node* l, Node* r) : left(l), right(r) {}

    ~BinaryOp() {
        delete left;
        delete right;
    }

    auto eval(std::ostream& os, Context& context) const {
        int reg1 = context.get_reg();
        int reg2 = context.get_reg();
        left->compile(os, reg1, context);
        right->compile(os, reg2, context);
        return RegPair {reg1, reg2};
    }

    void free(int reg1, int reg2, Context& context) const {
        context.free_reg(reg1);
        context.free_reg(reg2);
    }

    Node* left;
    Node* right;

};