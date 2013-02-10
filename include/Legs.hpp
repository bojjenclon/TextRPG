#ifndef GREAVES_HPP
#define GREAVES_HPP


#include "Armor.hpp"

class Greaves : public Armor {
    public:
        Greaves(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
