#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>

class Context {

public:

    Context() {}

    ~Context() {
        while (!scope_stack.empty()) {
            delete scope_stack.top();
            scope_stack.pop();
        }
    }

    void new_scope(std::string identifier) {
        scope_stack.push(new Scope(identifier));
    }

    void leave_scope() {
        delete scope_stack.top();
        scope_stack.pop();
    }

    void new_variable(std::string type, bool is_pointer, std::string identifier) {
        scope_stack.top()->new_variable(type, is_pointer, identifier);
    }

    VarInfo* find_variable(std::string identifier) {
        std::stack<Scope*> temp_stack;
        while (!scope_stack.empty()) {
            VarInfo* v = scope_stack.top()->find_variable(identifier);
            if (v != nullptr) {
                while (!temp_stack.empty()) {
                    scope_stack.push(temp_stack.top());
                    temp_stack.pop();
                }
                return v;
            }
            temp_stack.push(scope_stack.top());
            scope_stack.pop();
        }
        while (!temp_stack.empty()) {
            scope_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        return nullptr;
    }

    std::stack<Scope*> scope_stack;

};

class Scope {

public:

    Scope(std::string i) : identifier(i) {}

    ~Scope() {
        for (auto v : variables) {
            delete v;
        }
    }

    void new_variable(std::string type, bool is_pointer, std::string identifier) {
        variables.push_back(new VarInfo(type, is_pointer, identifier));
    }

    VarInfo* find_variable(std::string identifier) {
        for (auto v : variables) {
            if (v->identifier == identifier) {
                return v;
            }
        }
        return nullptr;
    }

    std::string identifier;
    std::vector<VarInfo*> variables;

};

class VarInfo {

public:

    VarInfo(std::string t, bool p, std::string i)
        : type(t), is_pointer(p), identifier(i) {}

    std::string type;
    bool is_pointer;
    std::string identifier;

};