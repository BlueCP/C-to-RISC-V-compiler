#include "ast/function_def.hpp"

FunctionDef::FunctionDef(TypeSpec* t, Declarator* d, NodeList* c)
    : return_type(t), declarator(d), compound_statement(c) {}

FunctionDef::~FunctionDef() {
    delete return_type;
    delete declarator;
    delete compound_statement;
}

void FunctionDef::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.return_flag = false;
    context.function_declarator_start = true;
    std::string func_end_label = new_label("f_end");
    context.func_end_label = func_end_label;

    os << ".globl " << declarator->identifier << std::endl;

    context.function_def = true;
    declarator->compile(os, dest_reg, context); // Generate function header

    context.function_def = false;
    compound_statement->compile(os, dest_reg, context); // Generate function body

    context.function_declarator_start = false;

    os << "." << func_end_label << ":" << std::endl;

    context.function_def = true;
    declarator->compile(os, dest_reg, context); // Generate function footer
}
