#pragma once

#include "../node.hpp"

class AssignmentExpr : public Node {

public:

    AssignmentExpr(Node* l, std::string o, Node* r)
        : left(l), op(o), right(r) {

    }

    ~AssignmentExpr() {
        delete left;
        delete right;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO: variable assignment.
    }

    Node* left;
    std::string op;
    Node* right;

};