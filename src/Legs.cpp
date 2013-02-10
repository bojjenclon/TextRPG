#include "Legs.hpp"

Greaves::Greaves(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "legs", description, bonus) {
    setParent("armor");
}

