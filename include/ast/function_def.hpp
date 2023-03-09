#pragma once

#include "node.hpp"
#include "declarator.hpp"

class FunctionDef : public Node {

public:

    FunctionDef(std::string* _type, Declarator* _fd, std::vector<Node*>* _cs)
        : type(_type), declarator(_fd), compound_statement(_cs) {

    }

    ~FunctionDef() {
        delete type;
        delete declarator;
        for (auto s : *compound_statement) {
            delete s;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

    std::string* type;
    Declarator* declarator;
    std::vector<Node*>* compound_statement;

};