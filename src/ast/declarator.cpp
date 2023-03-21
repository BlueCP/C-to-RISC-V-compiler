#include "ast/declarator.hpp"

// TODO update these classes to work with more types than just int in the future.


Declarator::Declarator(std::string i) : identifier(i) {}

Declarator::Declarator(std::string i, bool p) : Node(i), pointer(p) {}

Declarator::~Declarator() {}

// By default, Declarator declares a single variable.
void Declarator::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    // Declarator::compile does not depend on dest_reg since it does not deal with 'values'.
    if (context.in_global()) {
        // TODO codegen declare a new global variable
        os << identifier << ":" << std::endl;
        os << ".zero " << size << std::endl;
    } else {
        context.new_variable(size, identifier);
    }
}


BasicDeclarator::BasicDeclarator(std::string i) : Declarator(i) {}

BasicDeclarator::BasicDeclarator(std::string i, bool p) : Declarator(i, p) {}

BasicDeclarator::~BasicDeclarator() {} // Nothing to delete.


InitDeclarator::InitDeclarator(Declarator* d, NodeList* l) : Declarator(d->identifier), initialisers(l) {
    pointer = d->pointer;
    size = d->size;
    delete d;
}

InitDeclarator::~InitDeclarator() {
    delete initialisers;
}

void InitDeclarator::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.array_size = initialisers->node_list.size();
    Declarator::compile(os, dest_reg, context);
    if (context.in_global()) {
        for (unsigned i = 0; i < initialisers->node_list.size(); i++) {
            // TODO codegen
            // Instance of Constant has identifier equal to the number it represents.
            initialisers->node_list[i]->compile(os, dest_reg,context);
        }
    } else {
        int fp_offset = context.find_fp_offset(identifier); // Get fp offset
        for (unsigned i = 0; i < initialisers->node_list.size(); i++) {
            initialisers->node_list[i]->compile(os, dest_reg, context);
            context.store_reg(os, dest_reg, fp_offset + (size * i));
        }
        // If the variable is not an array, this for loop will just execute once, giving the desired behaviour.
    }
}


ArrayDeclarator::ArrayDeclarator(std::string i) : Declarator(i) {}

void ArrayDeclarator::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    if (context.in_global()) {
        // TODO codegen declare a new global array
        auto l1 = new_label(identifier);
        os << l1 << ":" << std::endl;
        os << ".zero " << size << std::endl;


    } else {
        context.new_variable(size * context.array_size, identifier);
    }
}



FunctionDeclarator::FunctionDeclarator(std::string i, NodeList* p) : Declarator(i), parameter_list(p) {}

FunctionDeclarator::FunctionDeclarator(std::string i) : Declarator(i), parameter_list(new NodeList()) {}

FunctionDeclarator::~FunctionDeclarator() {
    delete parameter_list;
}

void FunctionDeclarator::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    if (context.function_declarator_start) {
        os << identifier << ":" << std::endl;
        context.new_scope(os, identifier);
        for (unsigned i = 0; i < parameter_list->node_list.size(); i++) {
            parameter_list->node_list[i]->compile(os, i + 10, context);
        }
    } else {
        context.leave_scope(os);
        os << "jr ra" << std::endl;
    }
}


ParameterDeclaration::ParameterDeclaration(TypeSpec* t, Declarator* d) : type(t), declarator(d) {}

ParameterDeclaration::~ParameterDeclaration() {
    delete type;
    delete declarator;
}

void ParameterDeclaration::compile(std::ostream& os, int dest_reg, Context& context) const {
    declarator->compile(os, dest_reg, context);
    int fp_offset = context.find_fp_offset(identifier);
    context.store_reg(os, dest_reg, fp_offset);
}
