#pragma once

#include "../../node.hpp"

class CaseStatement : public Node {

public:

    CaseStatement(Node* e, Node* s);

    ~CaseStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* expression;
    Node* statement;

};
