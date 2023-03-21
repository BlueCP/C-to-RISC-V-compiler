#pragma once

#include "../../node.hpp"

class SwitchStatement : public Node {

public:

    SwitchStatement(Node* e, Node* s);

    ~SwitchStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* expression;
    Node* statement;

};
