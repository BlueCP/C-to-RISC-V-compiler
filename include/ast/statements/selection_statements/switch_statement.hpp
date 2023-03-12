#pragma once

#include "../../node.hpp"

class SwitchStatement : public Node {

public:

    SwitchStatement(Node* e, Node* s) : expression(e), statement(s) {}

    ~SwitchStatement() {
        delete expression;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen add end label and update context.break_label.
        expression->compile(os, dest_reg, context); // Expression to be switched goes in dest_reg
        context.switch_cascade_reg = context.get_clean_reg(os);
        statement->compile(os, dest_reg, context);
        context.free_reg(context.switch_cascade_reg);
    }

    Node* expression;
    Node* statement;

};