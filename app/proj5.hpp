#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

#include "MyPriorityQueue.hpp"

struct Distance
{
	std::string str;
	int distance1;
	int distance2;
	Distance(const std::string & str = std::string(), const int & distance1 = 0,const int & distance2 = 0):str(str), distance1(distance1), distance2(distance2)
	{
		
	}
	bool operator<(const Distance & other) const
	{
		return this->distance1 + this->distance2 < other.distance1 + other.distance2;
	}
};

void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in);


std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words);

void getPath(std::unordered_map<std::string, std::pair<std::string, int>>  paths, std::vector< std::string > & ret, std::string  s2, std::string s1);

int estimateDistanceToend(const std::string & currentStr, const std::string & s2);

#endif 
