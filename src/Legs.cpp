#include "Legs.hpp"

Greaves::Greaves(const std::string& name, const std::string& description) : Armor(name, "legs", description) {
    setParent("armor");
}

