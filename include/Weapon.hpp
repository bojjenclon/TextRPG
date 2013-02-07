#ifndef WEAPON_HPP
#define WEAPON_HPP


#include "Item.hpp"

class Weapon : public Item {
    public:
        Weapon(const std::string&, const std::string&, const std::string&);
};

#endif
