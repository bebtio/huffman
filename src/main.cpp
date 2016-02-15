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
            huff->createTree();
            huff->getTree().printHuffmanTree();
            
            huff->printEncodedFile();
            std::cout << std::endl;
            huff->printOriginalFile();
        }
	}
    

  return(0);
    
}
