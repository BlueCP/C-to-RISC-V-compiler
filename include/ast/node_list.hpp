#pragma once

#include "node.hpp"

class NodeList : public Node {

public:

    NodeList(Node* node);

    NodeList();

    ~NodeList();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    void add_node(Node* node);

    void add_list(NodeList* list);

    std::vector<Node*> node_list;

};
