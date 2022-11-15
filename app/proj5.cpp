#include "proj5.hpp"
#include <iostream>
// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}


// You probably want to change this function.
std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)
{
	if(s1 == std::string() || s2 == std::string() || s1 == s2 || s1.size() != s2.size()) return {};
	std::vector<std::string> ret;
	std::unordered_map<std::string, std::pair<std::string, int>> paths;
	std::unordered_set<std::string> visited;
	MyPriorityQueue<Distance> pq;
	
	pq.insert(Distance(s1, 0, estimateDistanceToend(s1, s2)));
	visited.insert(s1);
	while(!pq.isEmpty())
	{
		Distance previous = pq.min();
		int prevDistance = previous.distance1+1;
		pq.extractMin();
		for(size_t j = 0; j < previous.str.size(); ++j)
		{
			std::string currentStr = previous.str;
			for(char k = 'a'; k < 'z' + 1; ++k)
			{
				currentStr[j] = k;
				if(currentStr == previous.str)
				{
					continue;
				}
				if(currentStr == s2)
				{
					paths[s2] = std::make_pair(previous.str, prevDistance);
					getPath(paths, ret, s2, s1);
					return ret;
				}
				if(words.count(currentStr))
				{
					if(!visited.count(currentStr))
					{
						paths[currentStr] = std::make_pair(previous.str, prevDistance);
						visited.insert(currentStr);
						pq.insert(Distance(currentStr, prevDistance, estimateDistanceToend(currentStr, s2)));
					}
					else
					{
						if(prevDistance < paths[currentStr].second)
						{
							paths[currentStr] = std::make_pair(previous.str, prevDistance);
						}
					}
				}
			}
		}
	}
	return {};  // stub obviously 
}



void getPath(std::unordered_map<std::string, std::pair<std::string, int>>  paths, std::vector< std::string > & ret, std::string  s2, std::string  s1)
{
	std::string pos = s2;
	while(pos != s1)
	{
		ret.insert(std::begin(ret), pos);
		pos = paths[pos].first;
	}
	ret.insert(std::begin(ret), pos);
}

int estimateDistanceToend(const std::string & currentStr, const std::string & s2)
{
	int count = 0;
	for(size_t p = 0; p < s2.size(); ++p)
	{
		if(currentStr[p] != s2[p])
		{
			++count;
		}
	}
	return count;
}