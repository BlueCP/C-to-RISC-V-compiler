#include "ast/expressions/array_index.hpp"

ArrayIndex::ArrayIndex(Node* a, Node* i) : arr(a), index(i) {}

ArrayIndex::~ArrayIndex() {
    delete arr;
    delete index;
}

void ArrayIndex::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.array_offset_reg = context.get_reg();
    index->compile(os, context.array_offset_reg, context); // Evaluate array index

    arr->compile(os, dest_reg, context);

    context.free_reg(context.array_offset_reg);
    context.array_offset_reg = 0;
}
