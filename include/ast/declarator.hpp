#pragma once

#include "node.hpp"

class Declarator : public Node {

public:

    Declarator(std::string* _i)
        : identifier(_i) {

    }

    ~Declarator() {
        delete identifier;
    }

    std::string* identifier;
    bool pointer;

};

class FunctionDeclarator : public Declarator {

public:

    FunctionDeclarator(std::string* _i, std::vector<ParameterDeclaration*>* _p)
        : Declarator(_i), parameter_list(_p) {

    }

    ~FunctionDeclarator() {
        for (auto p : *parameter_list) {
            delete p;
        }
    }

    std::vector<ParameterDeclaration*>* parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(std::string* _t, Declarator* _d)
        : type(_t), declarator(_d) {

    }

    ~ParameterDeclaration() {
        delete type;
        delete declarator;
    }

private:

    std::string* type;
    Declarator* declarator;

};