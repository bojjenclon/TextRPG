#ifndef POTION_HPP
#define POTION_HPP


#include "Item.hpp"

class Potion : public Item {
    public:
        Potion(const std::string&, const std::string&, const std::string&);

        int getResto();

        int use();

        std::string toString();
};

#endif
