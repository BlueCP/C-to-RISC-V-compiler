#pragma once

#include "../node.hpp"

class Constant : public Node {

public:

    Constant(int n);

    void compile(std::ostream& os, int dest_reg, __attribute__((__unused__)) Context& context) const;

};

// This class refers to a variable or function call, as part of a primary expression.
class Identifier : public Node {

public:

    Identifier(std::string s);

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};
