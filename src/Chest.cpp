#include "Chest.hpp"

Chest::Chest(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "chest", description, bonus) {
    setParent("armor");
}
