#pragma once

#include "node.hpp"
#include "node_list.hpp"

class TypeSpec : public Node {

public:

    TypeSpec() {}

    TypeSpec(std::string i) : Node(i) {}

    virtual ~TypeSpec() {}

    int size; // In bytes
    bool is_signed = true; // Is this type signed? Assume true by default.

};

class PrimType : public TypeSpec {

public:

    PrimType(std::string i) : TypeSpec(i) {
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

    ~PrimType() {
        // Nothing to delete.
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // Don't generate any assembly.
    }

};

// EnumType is used if a variable or function is declared as type enum (identifier).
class EnumType : public TypeSpec {

public:

    EnumType(std::string i) : TypeSpec(i) {}

    ~EnumType() {
        // Nothing to delete.
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        // Don't generate any assembly.
    }

};

// EnumSpecifier creates a new enum, and adds the enumerator-value pairs to context.
class EnumSpecifier : public TypeSpec {

public:

    EnumSpecifier(NodeList* l) : TypeSpec(""), enum_list(l) {}

    EnumSpecifier(std::string i, NodeList* l) : TypeSpec(i), enum_list(l) {}

    ~EnumSpecifier() {
        delete enum_list;
    }

    void compile(std::ostream& os, int dest_reg, Context& context) const {
        context.enum_counter = 0;
        enum_list->compile(os, dest_reg, context);
    }

    NodeList* enum_list;

};
