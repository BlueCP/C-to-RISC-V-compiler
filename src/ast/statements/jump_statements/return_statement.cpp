#include "ast/statements/jump_statements/return_statement.hpp"

ReturnStatement::ReturnStatement(Node* _e) : expression(_e) {}

ReturnStatement::ReturnStatement() : expression(nullptr) {}

ReturnStatement::~ReturnStatement() {
    if (expression != nullptr) {
        delete expression;
    }
}

void ReturnStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    if (expression != nullptr) {
        expression->compile(os, 10, context); // Return always loads into register a0.
    }
    os << "j ." << context.func_end_label << std::endl;
}
