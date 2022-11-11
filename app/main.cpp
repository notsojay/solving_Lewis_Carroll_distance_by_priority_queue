#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include "proj5.hpp"
#include "MyPriorityQueue.hpp"

int main()
{
	std::string WORD_ONE = "putters";
	std::string WORD_TWO = "hampers";
	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);
	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);
	for(auto &i : r)
		std::cout << i << " ";
	return 0;
}

