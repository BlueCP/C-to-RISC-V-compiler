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

class Node {
public:
    virtual void compile(std::ostream& os, int dest_reg, Context& context) const = 0;
};