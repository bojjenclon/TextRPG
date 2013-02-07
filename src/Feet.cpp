#include "Feet.hpp"

Boots::Boots(const std::string& name, const std::string& description) : Armor(name, "feet", description) {
    setParent("armor");
}
