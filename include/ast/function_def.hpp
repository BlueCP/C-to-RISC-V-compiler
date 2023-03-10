#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "declarator.hpp"

class FunctionDef : public Node {

public:

    FunctionDef(std::string _type, Declarator* _fd, NodeList* _cs)
        : return_type(_type), declarator(_fd), compound_statement(_cs) {

    }

    ~FunctionDef() {
        delete declarator;
        delete compound_statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: codegen for function definition.
        // Note that arguments at the beginning of the function are handled by FunctionDeclarator::compile.
        std::string function_name = declarator->identifier;
        bool returns_pointer = declarator->pointer;
    }

    std::string return_type;
    Declarator* declarator;
    NodeList* compound_statement;

};