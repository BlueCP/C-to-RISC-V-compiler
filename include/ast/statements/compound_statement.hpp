#pragma once

#include "../node.hpp"
#include "../node_list.hpp"

class CompoundStatement : public Node {

public:

    CompoundStatement();

    CompoundStatement(NodeList* l1);

    CompoundStatement(NodeList* l1, NodeList* l2);

    ~CompoundStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    NodeList* list_1;
    NodeList* list_2;

};
