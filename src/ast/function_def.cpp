#include "ast/function_def.hpp"

FunctionDef::FunctionDef(TypeSpec* t, Declarator* d, Node* c)
    : return_type(t), declarator(d), compound_statement(c) {}

FunctionDef::~FunctionDef() {
    delete return_type;
    delete declarator;
    delete compound_statement;
}

void FunctionDef::compile(std::ostream& os, int dest_reg, Context& context) const {
    std::string func_end_label = new_label("f_end");
    context.func_end_label = func_end_label;

    os << ".globl " << declarator->identifier << std::endl;

    context.function_def = true;
    context.function_declarator_start = true;
    declarator->compile(os, dest_reg, context); // Generate function header

    compound_statement->compile(os, dest_reg, context); // Generate function body

    os << "." << func_end_label << ":" << std::endl;

    context.function_def = true;
    context.function_declarator_start = false;
    declarator->compile(os, dest_reg, context); // Generate function footer
}
