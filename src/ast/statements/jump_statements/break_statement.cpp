#include "ast/statements/jump_statements/break_statement.hpp"

BreakStatement::BreakStatement() {}

void BreakStatement::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    // TODO codegen jump to context.break_label.
    os << "j ." << context.break_label << std::endl;
}
