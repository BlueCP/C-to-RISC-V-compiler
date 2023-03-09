#pragma once

#include "../node.hpp"

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

class Identifier : public Node {

public:
    
    Identifier(std::string s)
        : identifier(s) {

    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        
    }

    std::string identifier;

};