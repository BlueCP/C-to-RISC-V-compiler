#pragma once

#include "../../node.hpp"

class ForStatement : public Node {

public:

    ForStatement(Node* i, Node* c, Node* u, Node* b)
        : initial_statement(i), condition(c), update_statement(u), body(b) {}
    
    ForStatement(Node* i, Node* c, Node* b)
        : initial_statement(i), condition(c), update_statement(nullptr), body(b) {}

    ~ForStatement() {
        delete initial_statement;
        delete condition;
        if (update_statement != nullptr) {
            delete update_statement;
        }
        delete body;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen
        // Note that if update_statement is a nullptr, then no update statement was provided.
    }

    Node* initial_statement;
    Node* condition;
    Node* update_statement;
    Node* body;

};