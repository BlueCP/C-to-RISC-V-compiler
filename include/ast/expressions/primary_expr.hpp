#pragma once

#include "../node.hpp"

class Constant : public Node {

public:

    Constant(int _n) : number(_n) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO put number in dest_reg.
    }

    int number;

};

// This class refers to a variable or function call, as part of a primary expression.
class Identifier : public Node {

public:
    
    Identifier(std::string s) : identifier(s) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO put number corresponding to variable corresponding to identifier in des_reg.

        // Note that Identifier is used as part of more complex expressions, such as
        // array accesses and funciton calls. However, that implementation is left to those
        // classes in the AST. Therefore, this function should just assume it is being used
        // to get the value of a variable.
    }

    std::string identifier;

};