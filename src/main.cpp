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
		if(huff->fileReader(argv[1]))
        {
            huff->printVector();
            huff->createTree();
            huff->getTree().printHuffmanTree();
        }
	}
    

  return(0);
    
}
