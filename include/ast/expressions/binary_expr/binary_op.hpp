#pragma once

#include "../../node.hpp"

class BinaryOp : public Node {

public:

    BinaryOp(Node* l, Node* r);

    ~BinaryOp();

    auto eval(std::ostream& os, Context& context) const;

    void free(int reg1, int reg2, Context& context) const;

    Node* left;
    Node* right;

};
