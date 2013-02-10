#include "Head.hpp"

Head::Head(const std::string& name, const std::string& description, const int& bonus)
: Armor(name, "head", description, bonus) {
    setParent("armor");
}

