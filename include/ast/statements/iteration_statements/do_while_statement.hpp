#pragma once

#include "../../node.hpp"

class DoWhileStatement : public Node {

public:

    DoWhileStatement(Node* s, Node* c) : statement(s), condition(c) {}

    ~DoWhileStatement() {
        delete condition;
        delete statement;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen
        std::string l1 = new_label(l1);
        std::cout << "." << l1 << ":" << std::endl;        
        statement->compile(os, dest_reg, context);
        condition->compile(os, dest_reg, context);
        std::cout << "bne " << reg_name[dest_reg] << ", 0, ." << l1 << std::endl;
    }

    Node* condition;
    Node* statement;

};