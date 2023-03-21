#include "ast/enum/enumerator.hpp"

Enumerator::Enumerator(std::string i) : Node(i), expr(nullptr) {}

Enumerator::Enumerator(std::string i, Node* v) : Node(i), expr(v) {}

Enumerator::~Enumerator() {
    delete expr;
}

void Enumerator::compile(__attribute__((__unused__)) std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    // Note that an enum declaration does not directly produce any assembly,
    // all logic is handled by the compiler at compile-time.
    if (expr == nullptr) {
        context.enum_map[identifier] = context.enum_counter;
    } else {
        context.enum_map[identifier] = expr->value;
        context.enum_counter = expr->value;
    }
    context.enum_counter++;
}
