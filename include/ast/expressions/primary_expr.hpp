#pragma once

#include "../node.hpp"

class Constant : public Node {

public:

    Constant(int n) : Node(std::to_string(n)), number(n) {
        value = n;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen put number in dest_reg.
    }

    int number;

};

// This class refers to a variable or function call, as part of a primary expression.
class Identifier : public Node {

public:
    
    Identifier(std::string s) : Node(s) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        if (context.enum_map.contains(identifier)) {
            Constant temp_constant(context.enum_map[identifier]);
            temp_constant.compile(os, dest_reg, context);
            // Enums can be treated as constants for our purposes.
        } else {
            int fp_offset = context.find_fp_offset(identifier);
            if (context.storing_var) {
                context.store_reg(os, dest_reg, fp_offset);
            } else {
                context.load_reg(os, dest_reg, fp_offset);
            }
        }
    }

};