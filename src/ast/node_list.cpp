#include "ast/node_list.hpp"


NodeList::NodeList(Node* node) {
    node_list.push_back(node);
}

NodeList::NodeList() {}

NodeList::~NodeList() {
    for (auto n : node_list) {
        delete n;
    }
}

void NodeList::compile(std::ostream& os, int dest_reg, Context& context) const {
    for (auto node : node_list) {
        node->compile(os, dest_reg, context);
    }
}

void NodeList::add_node(Node* node) {
    node_list.push_back(node);
}


// A statement list is like a node list, except it terminates if it sees a return flag in the context.
// Useful for lists of statements within functions.

StatementList::StatementList(Node* node) {
    node_list.push_back(node);
}

StatementList::StatementList() {}

void StatementList::compile(std::ostream& os, int dest_reg, Context& context) const {
    for (auto node : node_list) {
        node->compile(os, dest_reg, context);
        if (context.return_flag) {
            context.return_flag = false; // Reset flag
            break; // Terminate early on return
        }
    }
}
