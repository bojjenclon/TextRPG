#ifndef BOOTS_HPP
#define BOOTS_HPP

#include "Armor.hpp"

class Feet : public Armor {
    public:
        Feet(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
