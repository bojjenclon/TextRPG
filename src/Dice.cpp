#include <cstdlib>
#include <ctime>

#include "Functions.hpp"

#include "Dice.hpp"

int roll(int sides) {
	static bool init = false;
	
	if (!init) {
		srand(time(NULL));
		
		init = true;
	}
	
	return rand() % sides;
}
std::vector<int> rollSet(int dice, int sides) {
	std::vector<int> rolls(dice);
	
	for (int i = 0; i < dice; ++i) {
		rolls[i] = roll(sides);
	}
	
	return rolls;
}
std::vector<int> rollSortedSet(int dice, int sides, int discard) {
	std::vector<int> rolls = rollSet(dice, sides);
	
	insertionSort(rolls);
	
	if (discard > 0) {
		rolls.erase(rolls.begin(), rolls.begin() + discard);
	}
	
	return rolls;
}
int rollTotal(int dice, int sides, int discard) {
	std::vector<int> rolls = rollSortedSet(dice, sides, discard);
	
	int total = 0;
	
	for (unsigned int i = 0; i < rolls.size(); ++i) {
		total += rolls[i];
	}
	
	return total;
}
int rollHighest(int dice, int sides) {
	std::vector<int> rolls = rollSortedSet(dice, sides);
	
	return rolls.back();
}
