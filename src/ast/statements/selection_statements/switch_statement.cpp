#include "ast/statements/selection_statements/switch_statement.hpp"

SwitchStatement::SwitchStatement(Node* e, Node* s) : expression(e), statement(s) {}

SwitchStatement::~SwitchStatement() {
    delete expression;
    delete statement;
}

void SwitchStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    std::string end_label = new_label("switch_end");
    context.break_label = end_label;

    expression->compile(os, dest_reg, context); // Expression to be switched goes in dest_reg
    context.switch_cascade_reg = context.get_clean_reg(os);
    statement->compile(os, dest_reg, context);
    os << "." << end_label << ":" << std::endl;
    context.free_reg(context.switch_cascade_reg);
}
