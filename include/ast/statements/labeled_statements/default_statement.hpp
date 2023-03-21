#pragma once

#include "../../node.hpp"

class DefaultStatement : public Node {

public:

    DefaultStatement(Node* s);

    ~DefaultStatement();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    Node* statement;

};
