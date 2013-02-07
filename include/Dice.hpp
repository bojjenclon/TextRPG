#ifndef DICE_HPP
#define DICE_HPP

#include <vector>

int roll(int sides);
std::vector<int> rollSet(int dice, int sides);
std::vector<int> rollSortedSet(int dice, int sides, int discard=0);
int rollTotal(int dice, int sides, int discard=0);
int rollHighest(int dice, int sides);

#endif