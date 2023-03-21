#pragma once

#include "../../node.hpp"

class ContinueStatement : public Node {

public:

    ContinueStatement();

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

};
