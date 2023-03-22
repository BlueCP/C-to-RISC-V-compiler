#include "ast/statements/compound_statement.hpp"

CompoundStatement::CompoundStatement() : list_1(nullptr), list_2(nullptr) {}

CompoundStatement::CompoundStatement(Node* l1) : list_1(l1), list_2(nullptr) {}

CompoundStatement::CompoundStatement(Node* l1, Node* l2) : list_1(l1), list_2(l2) {}

CompoundStatement::~CompoundStatement() {
    if (list_1 != nullptr) {
        delete list_1;
    }
    if (list_2 != nullptr) {
        delete list_2;
    }
}

void CompoundStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.new_scope();
    if (list_1 != nullptr) {
        list_1->compile(os, dest_reg, context);
    }
    if (list_2 != nullptr) {
        list_2->compile(os, dest_reg, context);
    }
    context.leave_scope();
}
