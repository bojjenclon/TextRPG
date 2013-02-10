#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"

class Weapon : public Item {
    public:
        Weapon(const std::string& name, const std::string& id, const std::string& description, const int& damage);
		
	private:
		int damage_;
};

#endif
