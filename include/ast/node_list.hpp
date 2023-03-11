#pragma once

#include "node.hpp"

class NodeList : public Node {

public:

    NodeList(Node* node) {
        node_list.push_back(node);
    }

    NodeList() {}

    ~NodeList() {
        for (auto n : node_list) {
            delete n;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        for (auto node : node_list) {
            node->compile(os, dest_reg, context);
        }
    }

    void add_node(Node* node) {
        node_list.push_back(node);
    }

    std::vector<Node*> node_list;

};

// A statement list is like a node list, except it terminates if it sees a return flag in the context.
// Useful for lists of statements within functions.
class StatementList : public NodeList {

public:

    StatementList(Node* node) {
        node_list.push_back(node);
    }

    StatementList() {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        for (auto node : node_list) {
            node->compile(os, dest_reg, context);
            if (context.return_flag) {
                break; // Terminate early on return
            }
        }
    }

};