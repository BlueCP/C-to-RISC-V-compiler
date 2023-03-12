#pragma once

#include "../node.hpp"

class Enumerator : public Node {

public:

    Enumerator(std::string i) : Node(identifier), value(nullptr) {}

    Enumerator(std::string i, Node* v) : Node(i), value(v) {}

    ~Enumerator() {
        delete value;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        // TODO AST add enumerator-value pair to context.
    }

    Node* value;

};