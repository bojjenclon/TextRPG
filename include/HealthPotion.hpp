#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP

#include "Potion.hpp"

class HealthPotion : public Potion {
    public:
        HealthPotion(int potency);
		
		int use();
    private:
        const static std::string name[];
        const static std::string desc[];
        const static int resto[];

        int potency_;
};

#endif
