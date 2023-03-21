#pragma once

#include "../../node.hpp"

class BreakStatement : public Node {

public:

    BreakStatement();

    void compile(std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

};
