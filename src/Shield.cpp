#include "Shield.hpp"

Shield::Shield(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "shield", description, bonus) {
    setParent("armor");
}

