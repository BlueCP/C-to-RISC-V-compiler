#pragma once

#include "../../node.hpp"

class ContinueStatement : public Node {

public:

    ContinueStatement() {}

    void compile(std::ostream& os, int dest_reg, Context& context) {
        // TODO codegen jump to context.continue_label.
        std::cout << "j ." << context.continue_label << std::endl;
    }

};