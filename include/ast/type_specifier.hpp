#pragma once

#include "node.hpp"
#include "node_list.hpp"

class TypeSpec : public Node {

public:

    TypeSpec(std::string i) : Node(i) {
        if (i == "void") {
            size = 0;
        } else if (i == "char") {
            size = 1;
            is_signed = false;
        } else if (i == "int") {
            size = 4;
        } else if (i == "float") {
            size = 4;
        } else if (i == "double") {
            size = 8;
        } else if (i == "unsigned") {
            size = 4;
            is_signed = false;
        }
    }

    int size; // In bytes
    bool is_signed = true; // Is this type signed? Assume true by default.

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