#pragma once

#include "../../node.hpp"

class WhileStatement : public Node {

public:

    WhileStatement(Node* c, Node* s) : condition(c), statement(s) {}

    ~WhileStatement() {
        delete condition;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        std::string l1 = new_label("l1");
        std::string l2 = new_label("l2");
        std::cout << "." << l1 << ":" << std::endl;        
        condition->compile(os, dest_reg, context);
        std::cout << "beq " << reg_name[dest_reg] << ", 0, ." << l2 << std::endl;
        statement->compile(os, dest_reg, context);
        std::cout << "j ." << l1 << std::endl;
        std::cout << "." << l2 << ":" << std::endl;
        // Update context.continue_label and context.break_label.
    }

    Node* condition;
    Node* statement;

};