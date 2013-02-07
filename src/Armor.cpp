#include "Armor.hpp"

Armor::Armor(const std::string& name, const std::string& id, const std::string& description) : Item(name, id, description) {
    setParent("item");
    setEquipable(true);
}
