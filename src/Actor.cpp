#include <climits>

#include <boost/assign/list_of.hpp>

#include "Functions.hpp"
#include "Stats.hpp"
#include "HealthPotion.hpp"
#include "MagicPotion.hpp"

#include "Actor.hpp"

const boost::unordered_map<int, std::string> Actor::RACES = boost::assign::map_list_of
	(0, "Human")
	(1, "Dwarf")
	(2, "Elf")
	(3, "Gnome")
	(4, "Half-Elf")
	(5, "Halfling")
	(6, "Half-Orc")
;
const boost::unordered_map<int, std::string> Actor::PROFESSIONS = boost::assign::map_list_of
	(0, "Barbarian")
	(1, "Bard")
	(2, "Cleric")
	(3, "Druid")
	(4, "Fighter")
	(5, "Monk")
	(6, "Paladin")
	(7, "Ranger")
	(8, "Rogue")
	(9, "Sorcerer")
	(10, "Wizard")
;

Actor::Actor(std::string name[], bool gender, unsigned int race, unsigned int profession, unsigned int level) {
    name_[0] = name[0];
    name_[1] = name[1];

	if (race >= RACES.size()) {
		race = 0;
	}
	if (profession > PROFESSIONS.size()) {
		profession = 0;
	}

    gender_ = gender;
    race_ = race;
    profession_ = profession;

    level_ = 1;

    experience_ = 0;

    initializeStats(level);
	
	equipment_["head"] = boost::shared_ptr<Item>();
	equipment_["chest"] = boost::shared_ptr<Item>();
	equipment_["legs"] = boost::shared_ptr<Item>();
	equipment_["feet"] = boost::shared_ptr<Item>();
	equipment_["hands"] = boost::shared_ptr<Item>();
	equipment_["shoulders"] = boost::shared_ptr<Item>();
	equipment_["accessory1"] = boost::shared_ptr<Item>();
	equipment_["accessory2"] = boost::shared_ptr<Item>();
}

void Actor::initializeStats(int toLevel) {
	stats_ = generateStats(profession_);
	
	inv_ = boost::shared_ptr<Inventory>(new Inventory(((stats_["strength"] * 0.6f) + 0.5f)));
	
	boost::unordered_map<std::string, int> temp = boost::assign::map_list_of
		("hp", 0)
		("mp", 0)
		("strength", 0)
		("dexterity", 0)
		("constitution", 0)
		("intelligence", 0)
		("wisdom", 0)
		("charisma", 0)
		("ac", 0)
	;
	modifiers_ = temp;

    if (toLevel > 1) {
        experience_ = getExperienceNeeded(toLevel);

        for (int i = 1; i < toLevel; ++i) {
			levelUp();
        }
    }
}

std::string Actor::getName(int type) {
    switch(type) {
        case 0: {
            return name_[0];
        }
        case 1: {
            return name_[1];
        }
        case 2: {
            std::stringstream ss;

            ss << name_[0] << " " << name_[1];

            return ss.str();
        }
		case 3: {
			std::stringstream ss;

            ss << (gender_ ? "Ms." : "Mr.") << " " << name_[1];
			
			return ss.str();
		}
        default: {
            return "";
        }
    }
}

bool Actor::getGender() {
    return gender_;
}
int Actor::getRace() {
    return race_;
}
std::string Actor::getRaceName() {
	return RACES.at(race_);
}
int Actor::getProfession() {
    return profession_;
}
std::string Actor::getProfessionName() {
	return PROFESSIONS.at(profession_);
}

int Actor::getLevel() {
    return level_;
}
unsigned int Actor::getExperience() {
    return experience_;
}

int Actor::getStat(const std::string key) {
	return stats_.find(key) == stats_.end() ? -1 : stats_[key];
}
int Actor::getModifier(const std::string key)  {
	return modifiers_.find(key) == modifiers_.end() ? -1 : modifiers_[key];
}
int Actor::getModifiedStat(const std::string key)  {
	return stats_.find(key) == stats_.end() ? -1 : (stats_[key] + modifiers_[key]);
}

void Actor::setModifier(const std::string key, int value) {
	if (modifiers_.find(key) != modifiers_.end()) {
		modifiers_[key] = value;
	}
}
void Actor::modModifier(const std::string key, int mod) {
	if (modifiers_.find(key) != modifiers_.end()) {
		modifiers_[key] += mod;
	}
}

boost::shared_ptr<Item> Actor::equipped(const std::string key) {
	return equipment_.find(key) == equipment_.end() ? boost::shared_ptr<Item>() : equipment_[key];
}
bool Actor::equip(const std::string key, boost::shared_ptr<Item> value) {
	if (equipment_.find(key) != equipment_.end()) {
		if (value->isEquipable() && value->getID() == key) {
			equipment_[key] = value;
			
			return true;
		}
	}
	
	return false;
}

boost::shared_ptr<Inventory> Actor::getInventory() {
    return inv_;
}

bool Actor::addItem(boost::shared_ptr<Item> item) {
    return inv_->addItem(item);
}
void Actor::removeItem(int index) {
    inv_->removeItem(index);
}

void Actor::useItem(int index) {
	if (index > -1 && index < inv_->getNumItems()) {
		ptrItem item = inv_->getItem(index);
		
		if (item->getID() == "health potion") {
			int resto = inv_->usePotion(index);
			
			if (modifiers_["hp"] < 0) {
				modifiers_["hp"] += resto;
				
				if (modifiers_["hp"] > 0) {
					modifiers_["hp"] = 0;
				}
			}
		}
		else if (item->getID() == "magic potion") {
			int resto = inv_->usePotion(index);
			
			if (modifiers_["mp"] < 0) {
				modifiers_["mp"] += resto;
				
				if (modifiers_["mp"] > 0) {
					modifiers_["mp"] = 0;
				}
			}
		}
		else {
			
		}
	}
}

void Actor::useItem(ptrItem item) {
	if (item->getID() == "health potion") {
		int resto = item->use();
		
		if (modifiers_["hp"] < 0) {
			modifiers_["hp"] += resto;
			
			if (modifiers_["hp"] > 0) {
				modifiers_["hp"] = 0;
			}
		}
	}
	else if (item->getID() == "magic potion") {
		int resto = item->use();
		
		if (modifiers_["mp"] < 0) {
			modifiers_["mp"] += resto;
			
			if (modifiers_["mp"] > 0) {
				modifiers_["mp"] = 0;
			}
		}
	}
	else {
		
	}
}

void Actor::levelUp() {
    level_++;

	stats_["strength"] += 1;
	stats_["dexterity"] += 1;
	stats_["constitution"] += 1;
	stats_["intelligence"] += 1;
	stats_["wisdom"] += 1;
	stats_["charisma"] += 1;
	
	stats_["hp"] += (stats_["constitution"] / 10);
	stats_["mp"] += (stats_["intelligence"] / 10);

	inv_->setMaxSize(((stats_["strength"] * 0.6f) + 0.5f));
}

void Actor::addExperience(unsigned int exp) {
	if (experience_ == UINT_MAX) {
		return;
	}
	
	unsigned int prevExp = experience_;
	
    experience_ += exp;
	
	// Check if unsigned int wrapped around
	if (experience_ < prevExp) {
		experience_ = UINT_MAX;
	}

    checkExperience();
}

unsigned int Actor::getExperienceNeeded(int level) {
    if (level == 1) {
        return 0;
    }
    else {
		unsigned int expNeeded = (level * (level - 1) * 500);
		unsigned int overflowCheck = ((level - 1) * (level - 2) * 500);
		
		if (expNeeded < overflowCheck) {
			return 0;
		}
		
		return expNeeded;
    }
}

void Actor::checkExperience() {
    unsigned int experienceNeeded = getExperienceNeeded(level_ + 1);

	if (experienceNeeded == 0) {
		return;
	}

    while (experience_ >= experienceNeeded) {
        levelUp();

        experienceNeeded = getExperienceNeeded(level_ + 1);
		
		if (experienceNeeded == 0) {
			break;
		}
    }
}

std::string Actor::toString() {
    std::stringstream ss;

	ss << "---------------------------------" << "\n";

    ss << "Name: " << getName(2) << "\n";
	
	ss << "\n";
	
	ss << "Gender: " << (getGender() ? "Female" : "Male") << "\n";
	ss << "Race: " << getRaceName() << "\n";
	ss << "Profession: " << getProfessionName() << "\n";
	
	ss << "\n";
	
    ss << "Level: " << getLevel() << "\n";
    ss << "Experience: " << getExperience() << "\n";
    ss << "Next Level: " << getExperienceNeeded(getLevel() + 1) << "\n";
	
	ss << "\n";
	
	ss << "HP: " << getModifiedStat("hp") << " / " << getStat("hp") << "\n";
	ss << "MP: " << getModifiedStat("mp") << " / " << getStat("mp") << "\n";
	
	ss << "\n";
	
    ss << "Strength: " << getStat("strength") << "\n";
    ss << "Dexterity: " << getStat("dexterity") << "\n";
    ss << "Constitution: " << getStat("constitution") << "\n";
    ss << "Intelligence: " << getStat("intelligence") << "\n";
    ss << "Wisdom: " << getStat("wisdom") << "\n";
    ss << "Charisma: " << getStat("charisma") << "\n";
	
	ss << "---------------------------------" << "\n";

    return ss.str();
}
