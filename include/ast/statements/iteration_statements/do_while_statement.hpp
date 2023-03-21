#pragma once

#include "../../node.hpp"

class DoWhileStatement : public Node {

public:

    DoWhileStatement(Node* s, Node* c);

    ~DoWhileStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* statement;
    Node* condition;

};
