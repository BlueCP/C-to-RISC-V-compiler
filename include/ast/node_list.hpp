#pragma once

#include "node.hpp"

class NodeList : public Node {

public:

    NodeList(Node* node);

    NodeList();

    ~NodeList();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    void add_node(Node* node);

    std::vector<Node*> node_list;

};

// A statement list is like a node list, except it terminates if it sees a return flag in the context.
// Useful for lists of statements within functions.
class StatementList : public NodeList {

public:

    StatementList(Node* node);

    StatementList();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
