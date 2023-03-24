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
        VarInfo* global_var = context.find_global_var(identifier);
        if (global_var == nullptr) { // If this is a local variable
            VarInfo* var = context.find_local_var(identifier);
            if (context.storing_var) {
                context.store_reg(os, dest_reg, var->fp_offset, var->size == 1);
            } else {
                context.load_reg(os, dest_reg, var->fp_offset, var->size == 1);
            }
        } else { // If this is a global variable
            if (context.storing_var) {
                int temp_reg = context.get_clean_reg(os);
                os << "lui " << reg_name[temp_reg] << ",%hi(" << identifier << ")" << std::endl;
                if (context.array_indexing) {
                    os << "addi " << reg_name[temp_reg] << "," << reg_name[temp_reg] << ",%lo(" << identifier << ")" << std::endl;
                    os << "slli " << reg_name[context.array_offset_reg] << ", " << reg_name[context.array_offset_reg] << ", 2" << std::endl;
                    os << "add " << reg_name[context.array_offset_reg] << ", " << reg_name[context.array_offset_reg] << ", " << reg_name[temp_reg] << std::endl;
                    os << "nop" << std::endl;
                    os << "sw " << reg_name[dest_reg] << ", 0(" << reg_name[context.array_offset_reg] << ")" << std::endl;
                } else {
                    os << "nop" << std::endl; // Just in case
                    os << "sw " << reg_name[dest_reg] << ",%lo(" << identifier << ")(" << reg_name[temp_reg] << ")" << std::endl;
                }
                context.free_reg(temp_reg);
            } else {
                os << "lui " << reg_name[dest_reg] << ",%hi(" << identifier << ")" << std::endl;
                if (context.array_indexing) {
                    os << "addi " << reg_name[dest_reg] << ", " << reg_name[dest_reg] << ",%lo(" << identifier << ")" << std::endl;
                    os << "slli " << reg_name[context.array_offset_reg] << ", " << reg_name[context.array_offset_reg] << ", 2" << std::endl;
                    os << "add " << reg_name[context.array_offset_reg] << ", " << reg_name[context.array_offset_reg] << ", " << reg_name[dest_reg] << std::endl;
                    os << "lw " << reg_name[dest_reg] << ", 0(" << reg_name[context.array_offset_reg] << ")" << std::endl;
                } else {
                    os << "lw " << reg_name[dest_reg] << ",%lo(" << identifier << ")(" << reg_name[dest_reg] << ")" << std::endl;
                }
            }
        }
    }
}
