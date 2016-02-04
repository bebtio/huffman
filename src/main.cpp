#include <iostream>
#include "huffmanencoder.h"

int main(int argc, char **argv)
{
	HuffmanEncoder* huff = new HuffmanEncoder();

	if (argc != 2)
	{
		std::cout << argv[0] << "Usage: InputFile" << std::endl;
		return(-1);
	}
	else
	{
		huff->fileReader(argv[1]);
	}

	std::cout << "Before Sort" << std::endl;
	huff->printVector();

	huff->sortVector();

	std::cout << "After Sort" << std::endl;
	huff->printVector();
  return(0);
}
