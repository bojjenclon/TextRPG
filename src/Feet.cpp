#include "Feet.hpp"

Feet::Feet(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "feet", description, bonus) {
    setParent("armor");
}
