#ifndef HELMET_HPP
#define HELMET_HPP

#include "Armor.hpp"

class Head : public Armor {
    public:
        Head(const std::string& name, const std::string& description, const int& bonus=0);
};

#endif
