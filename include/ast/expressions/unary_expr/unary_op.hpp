#pragma once

#include "../../node.hpp"

class UnaryOp : public Node {

public:

    UnaryOp(Node* e);

    ~UnaryOp();

    Node* expr;

};
