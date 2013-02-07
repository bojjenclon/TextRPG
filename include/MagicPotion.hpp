#ifndef MAGICPOTION_HPP
#define MAGICPOTION_HPP

#include "Potion.hpp"

class MagicPotion : public Potion {
    public:
        MagicPotion(int potency);

        int getResto();
    private:
        const static std::string name[];
        const static std::string desc[];
        const static int resto[];

        int potency_;
};

#endif
