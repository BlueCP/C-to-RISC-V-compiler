#include "ast/statements/labeled_statements/default_statement.hpp"

DefaultStatement::DefaultStatement(Node* s) : statement(s) {
    identifier = "default";
}

DefaultStatement::~DefaultStatement() {
    delete statement;
}

void DefaultStatement::compile(std::ostream& os, int dest_reg, Context& context) const {
    if (context.case_headers) {
        std::string case_label = new_label("case");
        context.case_labels.push_back(case_label);
        os << "j ." << case_label << std::endl;
    } else {
        os << "." << context.case_labels[context.case_index] << ":" << std::endl;
        context.case_index++;
        statement->compile(os, dest_reg, context);
    }

    // auto l1 = new_label("l1");

    // os << "bne " << reg_name[context.switch_cascade_reg] << ", zero, ." << l1 << std::endl;
    // statement->compile(os, dest_reg, context);
    // os << "." << l1 << ":" << std::endl;

}
