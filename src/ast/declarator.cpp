#include "ast/declarator.hpp"

// TODO update these classes to work with more types than just int in the future.


Declarator::Declarator(std::string i) : identifier(i) {}

Declarator::Declarator(std::string i, bool p) : Node(i), pointer(p) {}

Declarator::~Declarator() {}


BasicDeclarator::BasicDeclarator(std::string i) : Declarator(i) {}

BasicDeclarator::BasicDeclarator(std::string i, bool p) : Declarator(i, p) {}

BasicDeclarator::~BasicDeclarator() {} // Nothing to delete.

// BasicDeclarator declares a single variable.
void BasicDeclarator::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    if (context.in_global()) {
        os << identifier << ":" << std::endl;
        os << ".zero " << size << std::endl;
    } else {
        context.new_variable(size, identifier);
    }
}


InitDeclarator::InitDeclarator(Declarator* d, NodeList* l) : Declarator(d->identifier), declarator(d), initialisers(l) {}

InitDeclarator::~InitDeclarator() {
    delete declarator;
    delete initialisers;
}

void InitDeclarator::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.array_size = initialisers->node_list.size();
    declarator->size = size; // Declaration modifies size of InitDeclarator;
    // Therefore we have to update the size of the child here.
    if (context.in_global()) {
        os << identifier << ":" << std::endl;
        for (unsigned i = 0; i < initialisers->node_list.size(); i++) {
            os << ".word " << initialisers->node_list[i]->value << std::endl;
        }
    } else {
        declarator->compile(os, dest_reg, context);
        int fp_offset = context.find_fp_offset(identifier); // Get fp offset
        for (unsigned i = 0; i < initialisers->node_list.size(); i++) {
            initialisers->node_list[i]->compile(os, dest_reg, context);
            context.store_reg(os, dest_reg, fp_offset + (size * i));
        }
        // If the variable is not an array, this for loop will just execute once, giving the desired behaviour.
    }
}


ArrayDeclarator::ArrayDeclarator(std::string i) : Declarator(i), array_size(nullptr) {}

ArrayDeclarator::ArrayDeclarator(std::string i, Node* s) : Declarator(i), array_size(s) {}

ArrayDeclarator::~ArrayDeclarator() {
    if (array_size != nullptr) {
        delete array_size;
    }
}

void ArrayDeclarator::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    if (array_size != nullptr) { // If an array size was defined, evaluate that.
        context.array_size = array_size->value;
    } else if (context.array_size == 0) {
        std::cout << "Array size not defined anywhere!" << std::endl;
    }
    if (context.in_global()) {
        os << identifier << ":" << std::endl;
        os << ".zero " << size * context.array_size << std::endl;
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
    if (context.function_def) {
        if (context.function_declarator_start) {
            os << identifier << ":" << std::endl;
            context.new_frame(os);
            for (unsigned i = 0; i < parameter_list->node_list.size(); i++) {
                parameter_list->node_list[i]->compile(os, i + 10, context);
            }
        } else {
            context.leave_frame(os);
            os << "jr ra" << std::endl;
        }
    } else {
        os << ".globl " << identifier << std::endl;
    }
}


ParameterDeclaration::ParameterDeclaration(TypeSpec* t, Declarator* d) : type(t), declarator(d) {}

ParameterDeclaration::~ParameterDeclaration() {
    delete type;
    delete declarator;
}

void ParameterDeclaration::compile(std::ostream& os, int dest_reg, Context& context) const {
    declarator->size = type->size;
    declarator->compile(os, dest_reg, context);
    int fp_offset = context.find_fp_offset(declarator->identifier);
    context.store_reg(os, dest_reg, fp_offset);
}
