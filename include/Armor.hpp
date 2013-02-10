#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "Item.hpp"

class Armor : public Item {
    public:
        Armor(const std::string& name, const std::string& id, const std::string& description, const int& bonus=0);
		
	private:
		int bonus_;
};

#endif
