#ifndef GAUNTLET_HPP
#define GAUNTLET_HPP

#include "Armor.hpp"

class Hands : public Armor {
    public:
        Hands(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
