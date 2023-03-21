#include "ast/utils.hpp"

// Create a unique label.
std::string new_label(std::string base) {
    return base + std::to_string(label_tracker++);
}
