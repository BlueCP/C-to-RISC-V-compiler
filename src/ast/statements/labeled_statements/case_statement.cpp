#include "ast/statements/labeled_statements/case_statement.hpp"

CaseStatement::CaseStatement(Node* e, Node* s) : expression(e), statement(s) {}

CaseStatement::~CaseStatement() {
    delete expression;
    delete statement;
}

void CaseStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    // dest_reg contains the value being switched.
    auto end = new_label("end");
    auto statementl = new_label("statement");

    int temp_reg = context.get_reg();

    os << "bne " << reg_name[context.array_offset_reg] << ", zero, ." << statementl << std::endl;
    expression->compile(os, temp_reg, context);
    os << "sub " << reg_name[temp_reg] << ", " << reg_name[dest_reg] << ", " << reg_name[temp_reg] << std::endl;
    os << "seqz " << reg_name[context.switch_cascade_reg] << ", " << reg_name[temp_reg] << std::endl;
    os << "beq " << reg_name[context.switch_cascade_reg] << ", zero, ." << end << std::endl;
    // TODO CODEGEN
    // If switch_cascade_reg is 1, skip to statement
    // If temp_reg and dest_reg are equal, assign 1 to context.switch_cascade_reg
    // If switch_cascade_reg is 0, skip to the end
    os << "." << statementl << ":" << std::endl;
    statement->compile(os, temp_reg, context);
    context.free_reg(temp_reg);

    os << "." << end << ":" << std::endl;
    // This implementation of switch is much less elegant and less efficient than the
    // standard way of doing it, but also much easier to write.
}
