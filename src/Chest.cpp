#include "Chest.hpp"

Cuirass::Cuirass(const std::string& name, const std::string& description) : Armor(name, "chest", description) {
    setParent("armor");
}
