#include <sstream>

#include "Potion.hpp"

Potion::Potion(const std::string& name, const std::string& id, const std::string& description) : Item(name, id, description) {
}

int Potion::getResto() {
    return -1;
}

int Potion::use() {
    return getResto();
}

std::string Potion::toString() {
    std::stringstream ss;

    ss << getName() << "; " << getDescription() << "; " << getResto();

    return ss.str();
}
