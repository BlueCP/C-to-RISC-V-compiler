#pragma once

#include "../node.hpp"

class CompoundStatement : public Node {

public:

    CompoundStatement();

    CompoundStatement(Node* l1);

    CompoundStatement(Node* l1, Node* l2);

    ~CompoundStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* list_1;
    Node* list_2;

};
