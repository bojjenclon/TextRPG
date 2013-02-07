#include "Hands.hpp"

Gauntlet::Gauntlet(const std::string& name, const std::string& description) : Armor(name, "hands", description) {
    setParent("armor");
}

