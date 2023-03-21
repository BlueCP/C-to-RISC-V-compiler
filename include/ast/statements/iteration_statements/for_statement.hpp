#pragma once

#include "../../node.hpp"

class ForStatement : public Node {

public:

    ForStatement(Node* i, Node* c, Node* u, Node* b);

    ForStatement(Node* i, Node* c, Node* b);

    ~ForStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* initial_statement;
    Node* condition;
    Node* update_statement;
    Node* body;

};
