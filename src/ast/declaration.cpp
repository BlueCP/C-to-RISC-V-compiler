#include "ast/declaration.hpp"

Declaration::Declaration(TypeSpec* t, std::vector<Declarator*> d)
    : type(t), declarators(d) {}

Declaration::~Declaration() {
    delete type;
    for (auto d : declarators) {
        delete d;
    }
}

void Declaration::compile(std::ostream& os, int dest_reg, Context& context) const {
    for (auto d : declarators) {
        d->size = type->size;
        d->compile(os, dest_reg, context);
    }
}
