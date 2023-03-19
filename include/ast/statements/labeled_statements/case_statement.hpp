#pragma once

#include "../../node.hpp"

class CaseStatement : public Node {

public:

    CaseStatement(Node* e, Node* s) : expression(e), statement(s) {}

    ~CaseStatement() {
        delete expression;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        // dest_reg contains the value being switched.
        auto end = new_label("end");
        auto statementl = new_label("statement"); 

        int temp_reg = context.get_reg();

        std::cout << "beq " << reg_name[context.array_offset_reg] << ", 1, ." << statementl << std::endl;   
        expression->compile(os, temp_reg, context);
        std::cout << "sub " << reg_name[temp_reg] << ", " << reg_name[dest_reg] << ", " << reg_name[temp_reg] << std::endl;
        std::cout << "seqz " << reg_name[context.switch_cascade_reg] << ", " << reg_name[temp_reg] << std::endl;
        std::cout << "beq " << reg_name[context.switch_cascade_reg] << ", 0, ." << end << std::endl;
        // TODO CODEGEN
        // If switch_cascade_reg is 1, skip to statement
        // If temp_reg and dest_reg are equal, assign 1 to context.switch_cascade_reg
        // If switch_cascade_reg is 0, skip to the end
        std::cout << "." << statementl << ":" << std::endl;
        statement->compile(os, temp_reg, context);
        context.free_reg(temp_reg);

        std::cout << "." << end << ":" << std::endl;
        // This implementation of switch is much less elegant and less efficient than the 
        // standard way of doing it, but also much easier to write.
    }

    Node* expression;
    Node* statement;

};