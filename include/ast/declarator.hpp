#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "type_specifier.hpp"

// TODO update these classes to work with more types than just int in the future.

class Declarator : public Node {

public:

    Declarator(std::string _i) : identifier(_i) {}

    Declarator(std::string i, bool p) : Node(i), pointer(p) {}

    // By default, Declarator declares a single variable.
    void compile(std::ostream& os, int dest_reg, Context& context) {
        if (context.in_global()) {
            // TODO codegen declare a new global variable
            std::cout << identifier << ":" << std::endl;
            std::cout << ".zero " << size << std::endl;
        } else {
            context.new_variable(size, identifier);
        }
    }

    std::string identifier;
    bool pointer;
    int size; // In bytes

};

class InitDeclarator : public Declarator {

public:

    InitDeclarator(Declarator* d, NodeList* l) : Declarator(d->identifier), initialisers(l) {
        pointer = d->pointer;
        size = d->size;
        delete d;
    }

    ~InitDeclarator() {
        delete initialisers;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        context.array_size = initialisers->node_list.size();
        Declarator::compile(os, dest_reg, context);
        if (context.in_global()) {
            for (int i = 0; i < initialisers->node_list.size(); i++) {
                // TODO codegen
                // Instance of Constant has identifier equal to the number it represents.
                initialisers->node_list[i]->compile(os, dest_reg,context);
            }
        } else {
            int fp_offset = context.find_fp_offset(identifier); // Get fp offset
            for (int i = 0; i < initialisers->node_list.size(); i++) {
                initialisers->node_list[i]->compile(os, dest_reg, context);
                context.store_reg(os, dest_reg, fp_offset + (size * i));
            }
            // If the variable is not an array, this for loop will just execute once, giving the desired behaviour.
        }
    }

    NodeList* initialisers;

};

class ArrayDeclarator : public Declarator {

public:

    ArrayDeclarator(std::string i) : Declarator(i) {}

    void compile(std::ostream& os, int dest_reg, Context& context) {
        if (context.in_global()) {
            // TODO codegen declare a new global array
            auto l1 = new_label(identifier);
            std::cout << l1 << ":" << std::endl;
            std::cout << ".zero " << size << std::endl;


        } else {
            context.new_variable(size * context.array_size, identifier);
        }
    }

};

class FunctionDeclarator : public Declarator {

public:

    FunctionDeclarator(std::string i, NodeList* p) : Declarator(i), parameter_list(p) {}

    FunctionDeclarator(std::string i) : Declarator(i), parameter_list(new NodeList()) {}

    ~FunctionDeclarator() {
        delete parameter_list;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        if (context.function_declarator_start) {
            std::cout << identifier << ":" << std::endl;
            context.new_scope(os, identifier);
            for (int i = 0; i < parameter_list->node_list.size(); i++) {
                parameter_list->node_list[i]->compile(os, i + 10, context);
            }
        } else {
            context.leave_scope(os);
            std::cout << "jr ra" << std::endl;
        }
    }

    NodeList* parameter_list;

};

class ParameterDeclaration : public Node {

public:

    ParameterDeclaration(TypeSpec* t, Declarator* d) : type(t), declarator(d) {}

    ~ParameterDeclaration() {
        delete type;
        delete declarator;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        declarator->compile(os, dest_reg, context);
        int fp_offset = context.find_fp_offset(identifier);
        context.store_reg(os, dest_reg, fp_offset);
    }

    TypeSpec* type;
    Declarator* declarator;

};
