#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

class HuffmanEncoder
{
public:
    HuffmanEncoder();
	~HuffmanEncoder();

	std::vector<std::pair<std::string, int > > getCharCount()
	{
		return(this->charCount);
	}

	void addChar(std::string in);
	
	void sortVector();
	void printVector();

	// This will sort the characters by frequency, putting the most frequent at the front of the vector, thats why
	// the larger value is seemingly on the wrong side.
	static bool sortByFrequency(const std::pair<std::string,int> smaller, const std::pair<std::string, int> larger)
	{
		return(smaller.second > larger.second);
	}

	void fileReader(std::string filename);
private:
	std::vector<std::pair< std::string, int> > charCount;
};

#endif // HUFFMANENCODER_H
