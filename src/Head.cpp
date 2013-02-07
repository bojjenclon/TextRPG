#include "Head.hpp"

Helmet::Helmet(const std::string& name, const std::string& description) : Armor(name, "head", description) {
    setParent("armor");
}

