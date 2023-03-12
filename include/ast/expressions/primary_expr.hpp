#pragma once

#include "../node.hpp"

class Constant : public Node {

public:

    Constant(int n) : Node(std::to_string(n)), number(n) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // TODO codegen put number in dest_reg.

        std::cout << "li " << reg_name[dest_reg] << " " << number << std::endl;
    }

    int number;

};

// This class refers to a variable or function call, as part of a primary expression.
class Identifier : public Node {

public:
    
    Identifier(std::string s) : Node(s) {}

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        int fp_offset = context.find_fp_offset(identifier);
        if (context.storing_var) {
            context.store_reg(os, dest_reg, fp_offset);
        } else {
            context.load_reg(os, dest_reg, fp_offset);
        }

        // Note that Identifier is used as part of more complex expressions, such as
        // array accesses and funciton calls. However, that implementation is left to those
        // classes in the AST. Therefore, this function should just assume it is being used
        // to get the value of a variable.
    }

};