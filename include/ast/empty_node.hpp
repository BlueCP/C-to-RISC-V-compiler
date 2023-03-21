#pragma once

#include "node.hpp"

class EmptyNode : public Node {

public:

    EmptyNode() {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        (void)os;
        (void)dest_reg;
        (void)context;
        // Do nothing (casts to void to suppress warnings).
    }

};
