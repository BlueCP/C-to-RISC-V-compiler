#include "ast/statements/selection_statements/if_statement.hpp"

IfStatement::IfStatement(Node* c, Node* s) : condition(c), statement(s) {}

IfStatement::~IfStatement() {
    delete condition;
    delete statement;
}

void IfStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto l1 = new_label("l1");
    statement->compile(os,dest_reg,context);
    os << "bne " << reg_name[dest_reg]  << ", 0, ." << l1 << std::endl;
    condition->compile(os, dest_reg, context);
    os << "." << l1 << ":" << std::endl;
}
