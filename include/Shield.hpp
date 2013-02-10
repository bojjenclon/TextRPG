#ifndef SHIELD_HPP
#define SHIELD_HPP


#include "Armor.hpp"

class Shield : public Armor {
    public:
        Shield(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
