#pragma once

#include "node.hpp"
#include "declarator.hpp"
#include "type_specifier.hpp"

class Declaration : public Node {

public:

    Declaration(TypeSpec* t, std::vector<Declarator*> d)
        : type(t), declarators(d) {}

    ~Declaration() {
        delete type;
        for (auto d : declarators) {
            delete d;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        for (auto d : declarators) {
            d->size = type->size;
            d->compile(os, dest_reg, context);
        }
        // Update this to work with more types (other than int) later.
    }

    TypeSpec* type;
    std::vector<Declarator*> declarators;

};