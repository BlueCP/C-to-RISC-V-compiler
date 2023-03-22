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

void NodeList::add_list(NodeList* list) {
    for (auto node : list->node_list) {
        node_list.push_back(node);
    }
}
