#include "ast/statements/iteration_statements/do_while_statement.hpp"

DoWhileStatement::DoWhileStatement(Node* s, Node* c) : statement(s), condition(c) {}

DoWhileStatement::~DoWhileStatement() {
    delete condition;
    delete statement;
}

void DoWhileStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    std::string l1 = new_label("l1");
    std::string l2 = new_label("l2");
    context.continue_label = l1;
    context.break_label = l2;

    os << "." << l1 << ":" << std::endl;
    statement->compile(os, dest_reg, context);
    condition->compile(os, dest_reg, context);
    os << "bne " << reg_name[dest_reg] << ", zero, ." << l1 << std::endl;
    // Update context.continue_label and context.break_label.
    os << "." << l2 << ":" << std::endl;
}
