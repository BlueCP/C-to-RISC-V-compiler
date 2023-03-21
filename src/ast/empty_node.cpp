#include "ast/empty_node.hpp"

EmptyNode::EmptyNode() {}

void EmptyNode::compile(std::ostream& os, int dest_reg, Context& context) const {
    (void)os;
    (void)dest_reg;
    (void)context;
    // Do nothing (casts to void to suppress warnings).
}
