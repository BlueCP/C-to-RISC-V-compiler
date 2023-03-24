#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <stack>

#include "utils.hpp"
#include "context.hpp"

struct RegPair {
    int reg1;
    int reg2;
};

class Node {

public:

    Node();

    Node(std::string i);

    virtual ~Node();

    virtual void compile(std::ostream& os, int dest_reg, Context& context) const = 0;

    std::string identifier = "";
    int value = 0;
    // To make things easier, I have given all nodes an identifier and integer value.

    bool is_signed = true; // Very bad but I'm out of time

};
