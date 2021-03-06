#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include <boost/algorithm/string.hpp>

#include "Actor.hpp"

#include "Weapon.hpp"
#include "Armor.hpp"
#include "Feet.hpp"
#include "Chest.hpp"
#include "Hands.hpp"
#include "Legs.hpp"
#include "Head.hpp"
#include "Shield.hpp"
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include "MagicPotion.hpp"

Actor* initPlayer() {
	std::string input;
	
	/* Get name (first and last) */
	
	std::string name[2];
	
	std::cout << "First name:" << "\n";

	while (true) {
		input.clear();
		
		std::cout << "-> ";
		
		getline(std::cin, input);
		
		if (input.empty()) {
			continue;
		}
		
		std::stringstream stream(input);
		
		if (stream >> name[0]) {
			break;
		}
	}
	
	std::cout << "Last name:" << "\n";
	
	while (true) {
		input.clear();
		
		std::cout << "-> ";
		
		getline(std::cin, input);

		if (input.empty()) {
			continue;
		}
		
		std::stringstream stream(input);
		
		if (stream >> name[1]) {
			break;
		}
	}
	
	/* Get gender */
	
	bool gender = false;
	
	std::cout << "Choose your gender:" << "\n";
	std::cout << "male" << "\n";
	std::cout << "female" << "\n";
	
	while (true) {
		input.clear();
		
		std::cout << "-> ";
		
		getline(std::cin, input);
		
		if (input.empty()) {
			continue;
		}
		
		if (boost::iequals(input, "female")) {
			gender = true;
			
			break;
		}
		else if(boost::iequals(input, "male")) {
			gender = false;
			
			break;
		}
	}
	
	/* Get race */
	
	int race = 0;
	
	std::cout << "Choose your race:" << "\n";
		
	for (unsigned int i = 0; i < Actor::RACES.size(); ++i) {
		std::cout << i << " - " << Actor::RACES.at(i) << "\n";
	}
	
	while (true) {
		input.clear();
		
		std::cout << "-> ";
		
		getline(std::cin, input);

		if (input.empty()) {
			continue;
		}
		
		std::stringstream stream(input);
		
		if (stream >> race) {
			break;
		}
	}
	
	/* Get profession */
	
	int profession = 0;
	
	std::cout << "Choose your profession:" << "\n";
		
	for (unsigned int i = 0; i < Actor::PROFESSIONS.size(); ++i) {
		std::cout << i << " - " << Actor::PROFESSIONS.at(i) << "\n";
	}
	
	while (true) {
		input.clear();
		
		std::cout << "-> ";
		
		getline(std::cin, input);

		if (input.empty()) {
			continue;
		}
		
		std::stringstream stream(input);
		
		if (stream >> profession) {
			break;
		}
	}
	
	return new Actor(name, gender, race, profession, 1);
}

void printEquipment(ptrActor player) {
	boost::shared_ptr<Item> item = player->equipped("head");
	std::cout << "Head: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("chest");
	std::cout << "Chest: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("legs");
	std::cout << "Legs: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("feet");
	std::cout << "Feet: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("hands");
	std::cout << "Hands: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("shoulders");
	std::cout << "Shoulders: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("accessory1");
	std::cout << "Accessory 1: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
	
	item = player->equipped("accessory2");
	std::cout << "Accessory 2: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << "\n";
	}
	else {
		std::cout << "<empty>" << "\n";
	}
}

int main(int argc, char* argv[]) {
    std::string name[] = {"Rallos", "Zendry"};
	ptrActor player = ptrActor(new Actor(name, false, 2, 6, 3));

	//ptrActor player = ptrActor(initPlayer());

	/* Initial Player Info */

    std::cout << player->toString() << "\n";

	/* Add Experience */

	unsigned int expToGrant = 15000; // UINT_MAX
    player->addExperience(expToGrant);

    std::cout << "\tYou have been granted 15,000 experience points." << "\n" << "\n";

    std::cout << player->toString() << "\n";

	/* Damage Player */
	
	player->setModifier("hp", -((player->getStat("hp") / 10.0f) + 0.5f));
	
	std::cout << "\tYou have been damaged by 10% of your maximum health.\n\n";

    std::cout << player->toString() << "\n";

    std::cout << "Inventory: " << "\n" << player->getInventory()->toString() << "\n\n";

	/* Add Items */

	player->addItem(ptrItem(new Head("Bronze Helm", "Simple bronze helmet.", 2)));
	player->addItem(ptrItem(new HealthPotion(0)));

    std::cout << "\tYou have been given a potion and a bronze helmet.\n\n";

    std::cout << "Inventory: " << "\n" << player->getInventory()->toString() << "\n";

	std::cout << "\n";
	
	printEquipment(player);
	
	std::cout << "\n";
	
	std::cout << "Using potion to restore your health.\n";
	
	player->useItem(1);
	
	std::cout << "\n";
	
	std::cout << player->toString() << "\n";
	
	std::cout << "Inventory: " << "\n" << player->getInventory()->toString() << "\n";

	std::cout << "\n";
	
	std::cout << "Equiping Fur Hat.\n";
	
	player->equip("head", ptrItem(new Head("Fur Hat", "A comfortable fur hat.")));
	
	std::cout << "\n";

	printEquipment(player);

    return EXIT_SUCCESS;
}
