#pragma once

#include "node.hpp"

class TranslationUnit : public Node {

public:

    TranslationUnit(Node* node) {
        branches.push_back(node);
    }

    ~TranslationUnit() {
        for (auto branch : branches) {
            delete branch;
        }
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        for (auto branch : branches) {
            branch->compile(os, dest_reg, context);
        }
    }

    std::vector<Node*> branches;

};