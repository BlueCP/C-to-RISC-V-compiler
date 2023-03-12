#pragma once

#include "../node.hpp"

class ArrayIndex : public Node {

public:

    ArrayIndex(Node* a, Node* i) : arr(a), index(i) {}

    ~ArrayIndex() {
        delete arr;
        delete index;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        context.array_offset_reg = context.get_reg();
        index->compile(os, context.array_offset_reg, context); // Evaluate array index

        arr->compile(os, dest_reg, context);

        context.free_reg(context.array_offset_reg);
        context.array_offset_reg = 0;
    }

    Node* arr;
    Node* index;

};