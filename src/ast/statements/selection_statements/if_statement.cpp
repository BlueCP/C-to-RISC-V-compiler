#include "ast/statements/selection_statements/if_statement.hpp"

IfStatement::IfStatement(Node* c, Node* s) : condition(c), statement(s) {}

IfStatement::~IfStatement() {
    delete condition;
    delete statement;
}

void IfStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto l1 = new_label("l1");
    condition->compile(os,dest_reg,context);
    os << "beq " << reg_name[dest_reg]  << ", zero, ." << l1 << std::endl;
    statement->compile(os, dest_reg, context);
    os << "." << l1 << ":" << std::endl;
}
