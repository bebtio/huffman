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
	huff->addChar("a");
	huff->addChar("c");
	huff->addChar("z");
	huff->addChar("z");
	huff->addChar("c");
	huff->addChar("c");
	huff->addChar("d");
	huff->addChar("d");
	huff->addChar("1");
	huff->addChar("1");
	huff->addChar("1");
	huff->addChar("1");

	std::cout << "Before Sort" << std::endl;
	huff->printVector();

	huff->sortVector();

	std::cout << "After Sort" << std::endl;
	huff->printVector();
  return(0);
}
