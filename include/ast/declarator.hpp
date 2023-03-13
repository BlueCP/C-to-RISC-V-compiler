#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "type_specifier.hpp"

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

    void compile(std::ostream& os, int dest_reg, Context& context) {
        context.array_size = initialisers->node_list.size();
        declarator->compile(os, dest_reg, context);
        if (context.in_global()) {
            for (int i = 0; i < initialisers->node_list.size(); i++) {
                // TODO codegen
                // Instance of Constant has identifier equal to the number it represents.
            }
        } else {
            int fp_offset = context.find_fp_offset(declarator->identifier); // Get fp offset
            for (int i = 0; i < initialisers->node_list.size(); i++) {
                initialisers->node_list[i]->compile(os, dest_reg, context);
                context.store_reg(os, dest_reg, fp_offset + (4 * i));
            }
            // If the variable is not an array, this for loop will just execute once, giving the desired behaviour.
        }
    }

    Declarator* declarator;
    NodeList* initialisers;

};

class ArrayDeclarator : public Declarator {

public:

    ArrayDeclarator(std::string i) : Declarator(i) {}

    void compile(std::ostream& os, int dest_reg, Context& context) {
        if (context.in_global()) {
            // TODO codegen declare a new global array
        } else {
            context.new_variable(4 * context.array_size, identifier);
        }
    }

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
            std::cout << identifier << ":" << std::endl;
            //compile the rest
        } else{
            // TODO function definition footer.
            std::cout << "jr ra" << std::endl;
        }
    }

    std::vector<ParameterDeclaration*> parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(TypeSpec* t, Declarator* d) : type(t), declarator(d) {}

    ~ParameterDeclaration() {
        delete type;
        delete declarator;
    }

    TypeSpec* type;
    Declarator* declarator;

};