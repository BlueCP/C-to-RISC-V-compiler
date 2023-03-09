#pragma once

#include "node.hpp"

class Constant : public Node {

public:

    Constant(int _n)
        : number(_n) {

    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO
    }

    int number;

};