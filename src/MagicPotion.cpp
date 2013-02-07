#include "MagicPotion.hpp"

const std::string MagicPotion::name[] = {
	"Lesser Mana Potion",
	"Small Mana Potion"
};
const std::string MagicPotion::desc[] = {
	"Heals a tiny amount of mana",
	"Heals a small amount of mana"
};
const int MagicPotion::resto[] = {
	5,
	10
};

MagicPotion::MagicPotion(int potency) : Potion(name[potency], "magic potion", desc[potency]) {
    potency_ = potency;
}

int MagicPotion::getResto() {
    return resto[potency_];
}
