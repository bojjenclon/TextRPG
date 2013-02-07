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
	
	std::cout << "First name:" << std::endl;

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
	
	std::cout << "Last name:" << std::endl;
	
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
	
	std::cout << "Choose your gender:" << std::endl;
	std::cout << "male" << std::endl;
	std::cout << "female" << std::endl;
	
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
	
	std::cout << "Choose your race:" << std::endl;
		
	for (unsigned int i = 0; i < Actor::RACES.size(); ++i) {
		std::cout << i << " - " << Actor::RACES.at(i) << std::endl;
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
	
	std::cout << "Choose your profession:" << std::endl;
		
	for (unsigned int i = 0; i < Actor::PROFESSIONS.size(); ++i) {
		std::cout << i << " - " << Actor::PROFESSIONS.at(i) << std::endl;
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

void printEquipment(Actor* player) {
	boost::shared_ptr<Item> item = player->equipped("head");
	std::cout << "Head: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("chest");
	std::cout << "Chest: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("legs");
	std::cout << "Legs: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("feet");
	std::cout << "Feet: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("hands");
	std::cout << "Hands: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("shoulders");
	std::cout << "Shoulders: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("accessory1");
	std::cout << "Accessory 1: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
	
	item = player->equipped("accessory2");
	std::cout << "Accessory 2: ";
	if (item) {
		std::cout << item->getName() << ", " << item->getDescription() << std::endl;
	}
	else {
		std::cout << "<empty>" << std::endl;
	}
}

int main(int argc, char* argv[]) {
    std::string name[] = {"Rallos", "Zendry"};
	Actor* player = new Actor(name, false, 2, 6, 3);

	//Actor* player = initPlayer();

	/* Initial Player Info */

    std::cout << player->toString() << std::endl;

	/* Add Experience */

	unsigned long expToGrant = 15000; // UINT_MAX
    player->addExperience(expToGrant);

    std::cout << "\tYou have been granted 15,000 experience points." << std::endl << std::endl;

    std::cout << player->toString() << std::endl;

	/* Damage Player */
	
	player->setModifier("hp", -((player->getStat("hp") / 10.0f) + 0.5f));
	
	std::cout << "\tYou have been damaged by 10% of your maximum health." << std::endl << std::endl;

    std::cout << player->toString() << std::endl;

    std::cout << "Inventory: " << std::endl << player->getInventory()->toString() << std::endl << std::endl;

	/* Add Items */

	player->addItem(boost::shared_ptr<Item>(new Helmet("Bronze Helm", "Simple bronze helmet.")));
	player->addItem(boost::shared_ptr<Item>(new HealthPotion(0)));

    std::cout << "\tYou have been given a potion and a bronze helmet." << std::endl << std::endl;

    std::cout << "Inventory: " << std::endl << player->getInventory()->toString() << std::endl;

	std::cout << std::endl;
	
	printEquipment(player);
	
	std::cout << std::endl;
	
	player->equip("head", boost::shared_ptr<Item>(new Helmet("Fur Hat", "A comfortable fur hat.")));

	printEquipment(player);

	delete player;

    return EXIT_SUCCESS;
}
