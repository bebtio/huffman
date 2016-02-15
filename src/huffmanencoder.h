#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
#include "leafnode.h"
#include "huffmantree.h"

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
    int getSumOfPairsOfChairs(int x, int y);
	
	void sortVector();
	void printVector();
    int getSumOfChars();

	// This will sort the characters by frequency, putting the most frequent at the front of the vector, thats why
	// the larger value is seemingly on the wrong side.
	static bool sortByFrequency(const std::pair<std::string,int> smaller, const std::pair<std::string, int> larger)
	{
		return(smaller.second < larger.second);
	}

	bool fileReader(std::string filename);
    void printEncodedFile();
    void printOriginalFile();
    void createTree();
    huffmantree getTree() { return(this->tree);}

private:
    
    std::vector<std::string> theFileStrings;
    int sumOfChars;
	std::vector<std::pair< std::string, int> > charCount;
    huffmantree tree;
    

};



#endif // HUFFMANENCODER_H
