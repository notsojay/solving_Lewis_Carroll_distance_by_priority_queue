#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include "proj5.hpp"
#include "MyPriorityQueue.hpp"

int main()
{
	std::string WORD_ONE = "changes";
	std::string WORD_TWO = "smashed";
	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);
	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);
	for(auto &i : r)
		std::cout << i << " ";
	std::cout << '\n' << r.size();
	return 0;
}

