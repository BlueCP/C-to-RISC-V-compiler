#pragma once

#include "node.hpp"
#include "node_list.hpp"

class TypeSpec : public Node {

public:

    TypeSpec();

    TypeSpec(std::string i);

    virtual ~TypeSpec();

    int size; // In bytes
    bool is_signed = true; // Is this type signed? Assume true by default.

};

class PrimType : public TypeSpec {

public:

    PrimType(std::string i);

    ~PrimType();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};

// EnumType is used if a variable or function is declared as type enum (identifier).
class EnumType : public TypeSpec {

public:

    EnumType(std::string i);

    ~EnumType();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

};

// EnumSpecifier creates a new enum, and adds the enumerator-value pairs to context.
class EnumSpecifier : public TypeSpec {

public:

    EnumSpecifier(NodeList* l);

    EnumSpecifier(std::string i, NodeList* l);

    ~EnumSpecifier();

    void compile(std::ostream& os, int dest_reg, Context& context) const;

    NodeList* enum_list;

};
