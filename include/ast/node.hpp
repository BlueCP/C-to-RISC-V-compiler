#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "context.hpp"

class Node {
public:
    virtual void compile(std::ostream& os, int dest_reg, Context& context) const = 0;
};