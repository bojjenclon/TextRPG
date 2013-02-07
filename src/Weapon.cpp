#include "Weapon.hpp"

Weapon::Weapon(const std::string& name, const std::string& id, const std::string& description) : Item(name, id, description) {
    setParent("item");
    setEquipable(true);
}
