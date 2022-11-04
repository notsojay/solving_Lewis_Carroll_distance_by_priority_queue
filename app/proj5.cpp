#include "proj5.hpp"
#include <string>
#include <sstream>
#include <unordered_set>
#include <string>

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
	std::vector< std::string > ret;
	ret.push_back("foo");
	ret.push_back("bar");
	return ret;  // stub obviously 
}

