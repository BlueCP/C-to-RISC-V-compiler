#include "ast/node.hpp"

Node::Node() {}

Node::Node(std::string i) : identifier(i) {}

virtual Node::~Node () {}

virtual void Node::compile(std::ostream& os, int dest_reg, Context& context) const = 0;
