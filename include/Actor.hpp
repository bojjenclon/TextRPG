#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/unordered/unordered_map.hpp>

#include "Item.hpp"
#include "Inventory.hpp"

class Actor {
	public:
		static const boost::unordered_map<int, std::string> RACES;
		static const boost::unordered_map<int, std::string> PROFESSIONS;
	
        Actor(std::string name[], bool gender, unsigned int race, unsigned int profession, unsigned int level=1);

        void initializeStats(int toLevel=1);

        std::string getName(int type=0);

        bool getGender();
        int getRace();
		std::string getRaceName();
        int getProfession();
		std::string getProfessionName();
		
        int getLevel();
        unsigned int getExperience();
		
		int getStat(const std::string key);
		int getModifier(const std::string key);
		int getModifiedStat(const std::string key);

		void setModifier(const std::string key, int value);
		void modModifier(const std::string key, int mod);

		ptrItem equipped(const std::string key);
		bool equip(const std::string key, ptrItem value);

        ptrInventory getInventory();

		bool addItem(ptrItem item);
        void removeItem(int index);
		
		void useItem(int index);
		void useItem(ptrItem item);

        void levelUp();

        void addExperience(unsigned int exp);

        unsigned int getExperienceNeeded(int level);

        void checkExperience();

        std::string toString();
    private:
        std::string name_[2];

		/* Gender: false = male, true = female */
        bool gender_;
		/* Race: <races> */
        int race_;
		/* Profession: <professions> */
        int profession_;

        unsigned int level_;

        unsigned int experience_;

		boost::unordered_map<std::string, int> stats_;
		boost::unordered_map<std::string, int> modifiers_;

		boost::unordered_map<std::string, ptrItem> equipment_;

        ptrInventory inv_;
};

typedef boost::shared_ptr<Actor> ptrActor;

#endif
