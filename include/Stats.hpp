#ifndef STATS_HPP
#define STATS_HPP

#include <boost/unordered/unordered_map.hpp>

extern const std::string STAT_NAMES[];

boost::unordered_map<std::string, int> generateStats(int profession);

boost::unordered_map<std::string, int> defaultStats();

#endif
