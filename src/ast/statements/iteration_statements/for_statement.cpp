#include "ast/statements/iteration_statements/for_statement.hpp"

ForStatement::ForStatement(Node* i, Node* c, Node* u, Node* b)
    : initial_statement(i), condition(c), update_statement(u), body(b) {}

ForStatement::ForStatement(Node* i, Node* c, Node* b)
    : initial_statement(i), condition(c), update_statement(nullptr), body(b) {}

ForStatement::~ForStatement() {
    delete initial_statement;
    delete condition;
    if (update_statement != nullptr) {
        delete update_statement;
    }
    delete body;
}

void ForStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    // Note that if update_statement is a nullptr, then no update statement was provided.
    auto l1 = new_label("l1");
    auto l2 = new_label("l2");
    context.continue_label = l1;
    context.break_label = l2;

    initial_statement->compile(os, dest_reg, context);
    os << "." << l1 << ":" << std::endl;
    condition->compile(os, dest_reg, context);
    os << "beq " << reg_name[dest_reg] << ", zero, ." << l2 << std::endl;

    //body
    body->compile(os,dest_reg,context);

    if(update_statement != nullptr){
        update_statement->compile(os, dest_reg, context);
    }
    os << "j ." << l1 << std::endl;
    os << "." << l2 << ":" << std::endl;
    // Update context.continue_label and context.break_label.
}
