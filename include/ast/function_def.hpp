#pragma once

#include "node.hpp"
#include "declarator.hpp"

class FunctionDef : public Node {

public:

    FunctionDef(std::string _type, Declarator* _fd, std::vector<Node*> _cs)
        : return_type(_type), declarator(_fd), compound_statement(_cs) {

    }

    ~FunctionDef() {
        delete declarator;
        for (auto s : compound_statement) {
            delete s;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: codegen for function definition.
        // Note that arguments at the beginning of the function are handled by FunctionDeclarator::compile.
        std::string function_name = declarator->identifier;
        bool returns_pointer = declarator->pointer;
    }

    std::string return_type;
    Declarator* declarator;
    std::vector<Node*> compound_statement;

};