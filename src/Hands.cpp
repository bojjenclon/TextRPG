#include "Hands.hpp"

Hands::Hands(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "hands", description, bonus) {
    setParent("armor");
}

