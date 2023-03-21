#pragma once

#include "../node.hpp"

class Enumerator : public Node {

public:

    Enumerator(std::string i);

    Enumerator(std::string i, Node* v);

    ~Enumerator();

    void compile(__attribute__((__unused__)) std::ostream& os, __attribute__((__unused__)) int dest_reg, Context& context) const;

    Node* expr;

};
