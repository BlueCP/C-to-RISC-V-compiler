#pragma once

#include "node.hpp"

class Declaration : public Node {

public:

    Declaration(std::string t, std::vector<Declarator*> d)
        : type(t), declarators(d) {

    }

    ~Declaration() {
        for (auto d : declarators) {
            delete d;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: variable declaration.
        // Use InitDeclarator::compile as well.
    }

    std::string type;
    std::vector<Declarator*> declarators;

};