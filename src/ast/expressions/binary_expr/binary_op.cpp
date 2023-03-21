#include "ast/expressions/binary_expr/binary_op.hpp"

BinaryOp::BinaryOp(Node* l, Node* r) : left(l), right(r) {}

BinaryOp::~BinaryOp() {
    delete left;
    delete right;
}

RegPair BinaryOp::eval(std::ostream& os, Context& context) const {
    int reg1 = context.get_reg();
    int reg2 = context.get_reg();
    left->compile(os, reg1, context);
    right->compile(os, reg2, context);
    return RegPair {reg1, reg2};
}

void BinaryOp::free(int reg1, int reg2, Context& context) const {
    context.free_reg(reg1);
    context.free_reg(reg2);
}
