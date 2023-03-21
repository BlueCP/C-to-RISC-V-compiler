#include "ast/statements/iteration_statements/while_statement.hpp"

WhileStatement::WhileStatement(Node* c, Node* s) : condition(c), statement(s) {}

WhileStatement::~WhileStatement() {
    delete condition;
    delete statement;
}

void WhileStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    std::string l1 = new_label("l1");
    std::string l2 = new_label("l2");

    context.continue_label = l1;
    context.break_label = l2;

    os << "." << l1 << ":" << std::endl;
    condition->compile(os, dest_reg, context);
    os << "beq " << reg_name[dest_reg] << ", 0, ." << l2 << std::endl;
    statement->compile(os, dest_reg, context);
    os << "j ." << l1 << std::endl;
    os << "." << l2 << ":" << std::endl;
    // Update context.continue_label and context.break_label.
}
