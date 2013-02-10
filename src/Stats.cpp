#include <algorithm>

#include "Functions.hpp"
#include "Dice.hpp"

#include "Stats.hpp"

const std::string STAT_NAMES[] = {
	"hp",
	"mp",
	"strength",
	"dexterity",
	"constitution",
	"intelligence",
	"wisdom",
	"charisma",
	"ac"
};

boost::unordered_map<std::string, int> generateStats(int profession) {
    switch(profession) {
        default: {
            return defaultStats();
		}
    }
}

boost::unordered_map<std::string, int> defaultStats() {
	/* hp, mp, strength, dexterity, constitution, intelligence, wisdom, charisma */
    boost::unordered_map<std::string, int> data(8);
	
	bool reroll = true;
	
	while (reroll) {
		for (unsigned int i = 2; i < 8; ++i) {
			 data[STAT_NAMES[i]] = rollTotal(4, 6, 1);
			
			 if (data[STAT_NAMES[i]] > 13) {
				 reroll = false;
			 }
		}
	}
	
	data["hp"] = std::max(rollHighest(2, 12), rollHighest(2, 12));
	data["mp"] = std::max(rollHighest(2, 8), rollHighest(2, 8));
	
	data["ac"] = 10;

    return data;
}
