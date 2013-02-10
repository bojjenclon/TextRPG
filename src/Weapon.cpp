#include "Weapon.hpp"

Weapon::Weapon(const std::string& name, const std::string& id, const std::string& description, const int& damage=0)
: Item(name, id, description) {
    setParent("item");
    setEquipable(true);
	
	damage_ = damage;
}
