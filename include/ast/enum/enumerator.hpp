#pragma once

#include "../node.hpp"

class Enumerator : public Node {

public:

    Enumerator(std::string i) : Node(identifier), expr(nullptr) {}

    Enumerator(std::string i, Node* v) : Node(i), expr(v) {}

    ~Enumerator() {
        delete expr;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        if (expr == nullptr) {
            context.enum_map[identifier] = context.enum_counter;
        } else {
            context.enum_map[identifier] = expr->value;
            context.enum_counter = expr->value;
        }
        context.enum_counter++;
    }

    Node* expr;

};