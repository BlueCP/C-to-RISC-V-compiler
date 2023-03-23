#include "ast/expressions/unary_expr/deref_expr.hpp"

DerefExpr::DerefExpr(Node* e) : UnaryOp(e) {}

void DerefExpr::compile(std::ostream& os, int dest_reg, Context& context) const {
    // TODO
    if(/*global*/1){
        //not sure see here x
    }else{
        int offset = context.find_fp_offset(expr->identifier);
        os << "lw " << reg_name[dest_reg] << ", -" << offset << "(fp)" << std::endl;
    }
}
