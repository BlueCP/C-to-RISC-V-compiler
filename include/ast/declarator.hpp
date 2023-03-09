#pragma once

#include "node.hpp"

class Declarator : public Node {

public:

    Declarator(std::string _i)
        : identifier(_i) {

    }

    std::string identifier;
    bool pointer;

};

class FunctionDeclarator : public Declarator {

public:

    FunctionDeclarator(std::string _i, std::vector<ParameterDeclaration*> _p)
        : Declarator(_i), parameter_list(_p) {
    }

    FunctionDeclarator(std::string _i)
        : Declarator(_i) {

    }

    ~FunctionDeclarator() {
        for (auto p : parameter_list) {
            delete p;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: Take care of arguments at the beginning of a function.
    }

    std::vector<ParameterDeclaration*> parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(std::string _t, Declarator* _d)
        : type(_t), declarator(_d) {

    }

    ~ParameterDeclaration() {
        delete declarator;
    }

    std::string type;
    Declarator* declarator;

};