#include "ast/expressions/primary_expr.hpp"

Constant::Constant(int n) : Node(std::to_string(n)) {
    value = n;
}

void Constant::compile(std::ostream& os, int dest_reg, __attribute__((__unused__)) Context& context) const {
    // Creating a constant has no dependence on context.
    os << "li " << reg_name[dest_reg] << ", " << value << std::endl;
}


Identifier::Identifier(std::string s) : Node(s) {}

void Identifier::compile(std::ostream& os, int dest_reg, Context& context) const {
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
