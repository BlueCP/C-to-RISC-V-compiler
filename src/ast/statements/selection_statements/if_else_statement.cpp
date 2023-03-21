#include "ast/statements/selection_statements/if_else_statement.hpp"

IfElseStatement::IfElseStatement(Node* c, Node* s1, Node* s2) : condition(c), if_stat(s1), else_stat(s2) {}

IfElseStatement::~IfElseStatement() {
    delete condition;
    delete if_stat;
    delete else_stat;
}

void IfElseStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    auto l1 = new_label("l1");
    auto l2 = new_label("l2");

    condition->compile(os, dest_reg, context);
    os << "beq " << reg_name[dest_reg] << ", 0, ." << l1 << std::endl;

    else_stat->compile(os, dest_reg, context);
    os << "j ." << l2 << std::endl;

    os << "." << l1 << ":" << std::endl;
    if_stat->compile(os, dest_reg, context);
    os << "." << l2 << ":" << std::endl;
}
