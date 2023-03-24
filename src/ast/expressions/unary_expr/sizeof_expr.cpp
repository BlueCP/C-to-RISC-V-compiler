#include "ast/expressions/unary_expr/sizeof_expr.hpp"

SizeofExpr::SizeofExpr(Node* e) : UnaryOp(e) {
    if (e->identifier == "void") {
        value = 0;
    } else if (e->identifier == "char") {
        value = 1;
    } else if (e->identifier == "int") {
        value = 4;
    } else if (e->identifier == "float") {
        value = 4;
    } else if (e->identifier == "double") {
        value = 8;
    } else if (e->identifier == "unsigned") {
        value = 4;
    } else {
        value = -1;
    }
}

void SizeofExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    if (value == -1) { // If this is a sizeof(variable) instead of sizeof(type name)
        int size = 0;
        VarInfo* local_var = context.find_local_var(expr->identifier);
        if (local_var == nullptr) {
            VarInfo* global_var = context.find_global_var(expr->identifier);
            if (global_var == nullptr) {
                std::cout << "Error: tried to find the size of a non-existent variable!" << std::endl;
            } else {
                size = global_var->size;
            }
        } else {
            size = local_var->size;
        }
        os << "li " << reg_name[dest_reg] << ", " << size << std::endl;
    } else {
        os << "li " << reg_name[dest_reg] << ", " << value << std::endl;
    }
}
