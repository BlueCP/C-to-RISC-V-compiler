#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <stack>

#include "context.hpp"

static std::string reg_name[32] = {
    "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static int label_tracker = 0;

struct RegPair {
    int reg1;
    int reg2;
};

// Create a unique label.
std::string new_label(std::string base) {
    return base + std::to_string(label_tracker++);
}

class Node {

public:

    Node() {}

    Node(std::string i) : identifier(i) {}

    virtual void compile(std::ostream& os, int dest_reg, Context& context) const = 0;

    std::string identifier = "";
    int value = 0;
    // To make things easier, I have given all nodes an identifier and integer value.

};