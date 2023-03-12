#pragma once

#include "node.hpp"
#include "node_list.hpp"

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
        if (context.in_global()) {
            declarator->compile(os, dest_reg, context); // Create label in global scope
            for (int i = 0; i < initialisers->node_list.size(); i++) {
                // TODO codegen
                // Instance of Constant has identifier equal to the number it represents.
            }
        } else {
            declarator->compile(os, dest_reg, context); // Prepare to add variable, allocate space in stack
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

    ArrayDeclarator(std::string i, bool p, int s) : Declarator(i), size(s) {}

    void compile(std::ostream& os, int dest_reg, Context& context) {
        context.new_variable(4 * size, identifier);
    }

    int size;

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

    ParameterDeclaration(std::string t, Declarator* d) : type(t), declarator(d) {}

    ~ParameterDeclaration() {
        delete declarator;
    }

    std::string type;
    Declarator* declarator;

};