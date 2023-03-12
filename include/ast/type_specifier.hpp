#pragma once

#include "node.hpp"
#include "node_list.hpp"

class TypeSpec : public Node {

public:

    TypeSpec(std::string i) : Node(i) {}

    TypeSpec(std::string i, int s) : Node(i), size(s) {}

    int size; // In bytes

};

// EnumType is used if a variable or function is declared as type enum (identifier).
class EnumType : public TypeSpec {

    EnumType(std::string i) : TypeSpec(i) {}

};

// EnumSpecifier creates a new enum, and adds the enumerator-value pairs to context.
class EnumSpecifier : public TypeSpec {

public:

    EnumSpecifier(NodeList* l) : TypeSpec(""), enum_list(l) {}

    EnumSpecifier(std::string i, NodeList* l) : TypeSpec(i), enum_list(l) {}

    ~EnumSpecifier() {
        delete enum_list;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) {
        context.enum_counter = 0;
        enum_list->compile(os, dest_reg, context);
    }

    NodeList* enum_list;

};