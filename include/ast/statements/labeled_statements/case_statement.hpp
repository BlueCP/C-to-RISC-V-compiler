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
        int temp_reg = context.get_reg();
        expression->compile(os, temp_reg, context);
        // TODO CODEGEN
        // If switch_cascade_reg is 1, skip to statement
        // If temp_reg and dest_reg are equal, assign 1 to context.switch_cascade_reg
        // If switch_cascade_reg is 0, skip to the end
        statement->compile(os, temp_reg, context);
        context.free_reg(temp_reg);

        // This implementation of switch is much less elegant and less efficient than the 
        // standard way of doing it, but also much easier to write.
    }

    Node* expression;
    Node* statement;

};