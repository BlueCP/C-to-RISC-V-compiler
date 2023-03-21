#pragma once

#include "../node.hpp"

class ArrayIndex : public Node {

public:

    ArrayIndex(Node* a, Node* i);

    ~ArrayIndex();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* arr;
    Node* index;

};
