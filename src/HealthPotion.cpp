#include "HealthPotion.hpp"

const std::string HealthPotion::name[] = {
	"Lesser Healing Potion",
	"Small Healing Potion"
};
const std::string HealthPotion::desc[] = {
	"Heals a tiny amount of health",
	"Heals a small amount of health"
};
const int HealthPotion::resto[] = {
	10,
	25
};

HealthPotion::HealthPotion(int potency) : Potion(name[potency], "health potion", desc[potency]) {
    potency_ = potency;
}

int HealthPotion::getResto() {
    return resto[potency_];
}
