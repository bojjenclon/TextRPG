#include "Shield.hpp"

Shield::Shield(const std::string& name, const std::string& description) : Armor(name, "shield", description) {
    setParent("armor");
}

