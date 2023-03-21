#include "ast/statements/jump_statements/continue_statement.hpp"

ContinueStatement::ContinueStatement() {}

void ContinueStatement::compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const {
    // TODO codegen jump to context.continue_label.
    os << "j ." << context.continue_label << std::endl;
}
