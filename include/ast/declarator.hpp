#pragma once

#include "node.hpp"
#include "node_list.hpp"
#include "type_specifier.hpp"

class Declarator : public Node {

public:

    Declarator(std::string i) : Node(i) {}

    Declarator(std::string i, bool p) : Node(i), pointer(p) {}

    // By default, Declarator declares a single variable.
    void compile(std::ostream& os, int dest_reg, Context& context) {
        if (context.in_global()) {
            // TODO codegen declare a new global variable
        } else {
            context.new_variable(4, identifier);
        }
    }

    bool pointer;

};

class InitDeclarator : public Node {

public:

    InitDeclarator(Declarator* d, NodeList* l) : declarator(d), initialisers(l) {}

    ~InitDeclarator() {
        delete declarator;
        delete initialisers;
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

    FunctionDeclarator(std::string i, std::vector<ParameterDeclaration*> p)
        : Declarator(i), parameter_list(p) {}

    FunctionDeclarator(std::string i) : Declarator(i) {}

    ~FunctionDeclarator() {
        for (auto p : parameter_list) {
            delete p;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        if (context.function_declarator_start) {
            // TODO codegen function name label.
            context.new_scope(os, identifier);
            // TODO codegen push argument registers to the stack.
        } else {
            context.leave_scope(os);
            // TODO codegen jump to return address.
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