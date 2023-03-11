#pragma once

#include "node.hpp"

class Declarator : public Node {

public:

    Declarator(std::string _i) : identifier(_i) {}

    Declarator(std::string i, bool p) : identifier(i), pointer(p) {}

    std::string identifier;
    bool pointer;

};

class InitDeclarator : public Declarator {

public:

    InitDeclarator(std::string i, bool p, Node* e) : Declarator(i, p), expression(e) {}

    ~InitDeclarator() {
        delete expression;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

    Node* expression;

};

class FunctionDeclarator : public Declarator {

public:

    FunctionDeclarator(std::string _i, std::vector<ParameterDeclaration*> _p)
        : Declarator(_i), parameter_list(_p) {}

    FunctionDeclarator(std::string _i) : Declarator(_i) {}

    ~FunctionDeclarator() {
        for (auto p : parameter_list) {
            delete p;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        if (context.function_declarator_start) {
            // TODO function definition header.
        } else {
            // TODO function definition footer.
        }
    }

    std::vector<ParameterDeclaration*> parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(std::string _t, Declarator* _d) : type(_t), declarator(_d) {}

    ~ParameterDeclaration() {
        delete declarator;
    }

    std::string type;
    Declarator* declarator;

};