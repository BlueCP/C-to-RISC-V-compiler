#pragma once

#include "../../node.hpp"

class BinaryOp : public Node {

public:

    BinaryOp(Node* l, Node* r)
        : left(l), right(r) {

    }

    ~BinaryOp() {
        delete left;
        delete right;
    }

    Node* left;
    Node* right;

};