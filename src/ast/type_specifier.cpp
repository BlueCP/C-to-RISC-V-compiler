#include "ast/type_specifier.hpp"


TypeSpec::TypeSpec() {}

TypeSpec::TypeSpec(std::string i) : Node(i) {}

virtual TypeSpec::~TypeSpec() {}


PrimType::PrimType(std::string i) : TypeSpec(i) {
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

PrimType::~PrimType() {
    // Nothing to delete.
}

void PrimType::compile(std::ostream& os, int dest_reg, Context& context) const {
    // Don't generate any assembly.
}


// EnumType is used if a variable or function is declared as type enum (identifier).

EnumType::EnumType(std::string i) : TypeSpec(i) {}

EnumType::~EnumType() {
    // Nothing to delete.
}

void EnumType::compile(std::ostream& os, int dest_reg, Context& context) const {
    // Don't generate any assembly.
}


// EnumSpecifier creates a new enum, and adds the enumerator-value pairs to context.

EnumSpecifier::EnumSpecifier(NodeList* l) : TypeSpec(""), enum_list(l) {}

EnumSpecifier::EnumSpecifier(std::string i, NodeList* l) : TypeSpec(i), enum_list(l) {}

EnumSpecifier::~EnumSpecifier() {
    delete enum_list;
}

void EnumSpecifier::compile(std::ostream& os, int dest_reg, Context& context) const {
    context.enum_counter = 0;
    enum_list->compile(os, dest_reg, context);
}
