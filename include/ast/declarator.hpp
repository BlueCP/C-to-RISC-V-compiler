#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "type_specifier.hpp"

// TODO update these classes to work with more types than just int in the future.

class Declarator : public Node {

public:

    Declarator(std::string i);

    Declarator(std::string i, bool p);

    virtual ~Declarator();

    // Declarator does not implement compile as it is an abstract base class.

    std::string identifier;
    bool pointer;
    int size; // In bytes

};

class BasicDeclarator : public Declarator {

public:

    BasicDeclarator(std::string i);

    BasicDeclarator(std::string i, bool p);

    ~BasicDeclarator();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};

class InitDeclarator : public Declarator {

public:

    InitDeclarator(Declarator* d, NodeList* l);

    ~InitDeclarator();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Declarator* declarator;
    NodeList* initialisers;

};

class ArrayDeclarator : public Declarator {

public:

    ArrayDeclarator(std::string i);

    ArrayDeclarator(std::string i, Node* s);

    ~ArrayDeclarator();

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

    Node* array_size; // Expression representing array size.

};

class FunctionDeclarator : public Declarator {

public:

    FunctionDeclarator(std::string i, NodeList* p);

    FunctionDeclarator(std::string i);

    ~FunctionDeclarator();

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

    NodeList* parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(TypeSpec* t, Declarator* d);

    ~ParameterDeclaration();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    TypeSpec* type;
    Declarator* declarator;

};
