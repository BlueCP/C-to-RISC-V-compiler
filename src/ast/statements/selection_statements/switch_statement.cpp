#include "ast/statements/selection_statements/switch_statement.hpp"

SwitchStatement::SwitchStatement(Node* e, Node* s) : expression(e), statement(s) {}

SwitchStatement::~SwitchStatement() {
    delete expression;
    delete statement;
}

// NOTE: under the current implementation, it is not possible to have nested switch statements.
void SwitchStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    std::string end_label = new_label("switch_end");
    context.break_label = end_label;
    context.case_labels.clear();
    context.case_index = 0;

    expression->compile(os, dest_reg, context); // Expression to be switched goes in dest_reg.

    context.case_headers = true;
    statement->compile(os, dest_reg, context);

    context.case_headers = false;
    statement->compile(os, dest_reg, context);

    os << "." << end_label << ":" << std::endl;

    // expression->compile(os, dest_reg, context); // Expression to be switched goes in dest_reg
    // context.switch_cascade_reg = context.get_clean_reg(os);
    // statement->compile(os, dest_reg, context);
    // os << "." << end_label << ":" << std::endl;
    // context.free_reg(context.switch_cascade_reg);
}
