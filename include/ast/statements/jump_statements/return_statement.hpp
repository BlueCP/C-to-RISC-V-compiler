#pragma once

#include "../../node.hpp"

class ReturnStatement : public Node {

public:

    ReturnStatement(Node* _e);

    ReturnStatement();

    ~ReturnStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* expression;

};
