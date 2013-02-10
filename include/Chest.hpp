#ifndef CUIRASS_HPP
#define CUIRASS_HPP

#include "Armor.hpp"

class Chest : public Armor {
    public:
        Chest(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
