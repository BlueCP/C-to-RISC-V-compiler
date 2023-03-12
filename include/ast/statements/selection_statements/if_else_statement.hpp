#pragma once

#include "../../node.hpp"

class IfElseStatement : public Node {

public:

    IfElseStatement(Node* c, Node* s1, Node* s2) : condition(c), if_stat(s1), else_stat(s2) {}

    ~IfElseStatement() {
        delete condition;
        delete if_stat;
        delete else_stat;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen
        auto l1 = new_label("l1");
        auto l2 = new_label("l2");

        condition->compile(os, dest_reg, context);
        std::cout << "beq " << reg_name[dest_reg] << ", 0, ." << l1 << std::endl;
        
        else_stat->compile(os, dest_reg, context);
        std::cout << "j ." << l2 << std::endl;

        std::cout << "." << l1 << ":" << std::endl;
        if_stat->compile(os, dest_reg, context);
        std::cout << "." << l2 << std::endl;
    }

    Node* condition;
    Node* if_stat;
    Node* else_stat;

};