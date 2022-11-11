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
	std::unordered_map<std::string, std::string> paths;
	MyPriorityQueue<Distance> pq;
	int distance1 = 0, distance2 = 0;
	pq.insert(Distance(s1, distance1, distance2));
	while(!pq.isEmpty())
	{
		Distance previous = pq.min();
		distance1 = previous.distance1 + 1;
		pq.extractMin();
		for(size_t j = 0; j < previous.str.size(); ++j)
		{
			std::string currentStr = previous.str;
			for(char k = 'a'; k <= 'z'; ++k)
			{
				currentStr[j] = k;
				if(currentStr == previous.str)
				{
					continue;
				}
				if(currentStr == s2)
				{
					paths[s2] = previous.str;
					getPath(paths, ret, s2, distance1);
					return ret;
				}
				if(words.count(currentStr) && paths.find(currentStr) == paths.end())
				{
					paths[currentStr] = previous.str;
					distance2 = 0;
					for(size_t p = 0; p < s2.size(); ++p)
					{
						if(currentStr[p] != s2[p])
						{
							++distance2;
						}
					}
					pq.insert(Distance(currentStr, distance1, distance2));
				}
			}
		}
	}
	return {};  // stub obviously 
}



void getPath(const std::unordered_map<std::string, std::string> & paths, std::vector< std::string > & ret, const std::string & s2, const int & distance)
{
	ret.resize(distance+1, "");
	ret[distance] = s2;
	for(int i = distance-1; i >= 0; --i)
	{
		ret[i] = paths.find(ret[i+1])->second;
	}
}