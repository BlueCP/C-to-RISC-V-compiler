#include "ast/expressions/array_index.hpp"

ArrayIndex::ArrayIndex(Node* a, Node* i) : arr(a), index(i) {}

ArrayIndex::~ArrayIndex() {
    delete arr;
    delete index;
}

void ArrayIndex::compile(std::ostream& os, int dest_reg, Context& context) const {
    bool storing_var = context.storing_var; // Keep a record of this for manipulation.

    context.array_offset_reg = context.get_reg();

    context.storing_var = false; // We want to load the index into reg, not store it.
    index->compile(os, context.array_offset_reg, context); // Evaluate array index

    context.storing_var = storing_var; // If we are overall storing a var, we can set the flag now.
    context.array_indexing = true;
    arr->compile(os, dest_reg, context);
    context.array_indexing = false;

    context.free_reg(context.array_offset_reg);
    context.array_offset_reg = 0;
}
