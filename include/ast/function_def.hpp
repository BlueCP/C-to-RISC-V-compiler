#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "declarator.hpp"
#include "type_specifier.hpp"

class FunctionDef : public Node {

public:

    FunctionDef(TypeSpec* t, Declarator* d, Node* c);

    ~FunctionDef();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    TypeSpec* return_type;
    Declarator* declarator;
    Node* compound_statement;

};
