#pragma once

#include "node.hpp"
#include "declarator.hpp"
#include "type_specifier.hpp"

class Declaration : public Node {

public:

    Declaration(TypeSpec* t, std::vector<Declarator*> d);

    ~Declaration();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    TypeSpec* type;
    std::vector<Declarator*> declarators;

};
