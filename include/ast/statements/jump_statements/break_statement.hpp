#pragma once

#include "../../node.hpp"

class BreakStatement : public Node {

public:

    BreakStatement() {}

    void compile(std::ostream& os, int dest_reg, Context& context) {
        // TODO codegen jump to context.break_label.
        std::cout << "j ." << context.break_label << std::endl;
    }

};