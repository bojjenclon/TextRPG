#include "Armor.hpp"

Armor::Armor(const std::string& name, const std::string& id, const std::string& description, const int& bonus)
: Item(name, id, description) {
    setParent("item");
    setEquipable(true);
	
	bonus_ = bonus;
}
