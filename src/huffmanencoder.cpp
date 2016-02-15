#include "huffmanencoder.h"

/********************************************************************************************/

HuffmanEncoder::HuffmanEncoder()
{
    this->sumOfChars = 0;
}

/********************************************************************************************/



/********************************************************************************************/


HuffmanEncoder::~HuffmanEncoder()
{

}


/********************************************************************************************/

bool HuffmanEncoder::fileReader(std::string filename)
{
    bool fileOpened = true;
    std::fstream inputFileStream;
    std::string tempString;
    std::string tempChar;
    inputFileStream.open(filename.c_str());
    
    if(!inputFileStream.is_open())
    {
        std::cout << filename << " could not be opened" << std::endl;
        fileOpened = false;
    }
    else
    {
        while (getline(inputFileStream, tempString))
        {
            theFileStrings.push_back(tempString);
            for (int i = 0; i < tempString.size();i++)
            {
                tempChar = tempString.at(i);
                addChar(tempChar);
            }
        }
    }
    
    return(fileOpened);
}

/********************************************************************************************/

// This function looks at the current character being read.  If it does not exist, add
// it to the vector and make its integer value equal to one.
// If it is already present in the vector increment its integer value.
void HuffmanEncoder::addChar(std::string in)
{
	bool success = true;
	if (this->charCount.empty() == true)
	{
		this->charCount.push_back(std::make_pair(in, 1));
	}
	else
	{
		for (unsigned int i = 0; i < this->charCount.size(); i++)
		{
			if (in == this->charCount.at(i).first)
			{
				this->charCount.at(i).second += 1;
                this->sumOfChars++;
				success = true;
				break;
			}
			else
			{
				success = false;
			}
			
		}

		if (success == false)
		{
			this->charCount.push_back(std::make_pair(in, 1));
            this->sumOfChars++;
		}
	}
    
    this->sortVector();
}

/********************************************************************************************/


void HuffmanEncoder::sortVector()
{
	std::sort(this->charCount.begin(), this->charCount.end(), sortByFrequency);
}

/********************************************************************************************/


void HuffmanEncoder::printVector()
{
	for (unsigned int i = 0; i < this->charCount.size(); i++)
	{
		std::cout << this->charCount.at(i).first << " " << this->charCount.at(i).second << std::endl;
	}
    
    std::cout << this->getSumOfChars() << std::endl;
}



/********************************************************************************************/


int HuffmanEncoder::getSumOfChars()
{
    return(this->sumOfChars);
}

/********************************************************************************************/

int HuffmanEncoder::getSumOfPairsOfChairs(int x, int y)
{
    int z = x + y;
    return(z);
}

/********************************************************************************************/

void HuffmanEncoder::createTree()
{
    this->tree.createLeafNodes(this->charCount);
}

/********************************************************************************************/

void HuffmanEncoder::printEncodedFile()
{
    std::cout << std::endl << "The Encoded File:" << std::endl << std::endl;
    for(int i = 0; i < theFileStrings.size(); i++)
    {
        for(int j = 0; j < theFileStrings.at(i).size(); j++)
        {
            std::cout << this->tree.getEncoding(this->theFileStrings.at(i).at(j));
        }
    }
}

/********************************************************************************************/

void HuffmanEncoder::printOriginalFile()
{
    std::cout << std::endl << "The Original File:" << std::endl << std::endl;

    for(int i = 0; i < theFileStrings.size(); i++)
    {
        std::cout << theFileStrings.at(i);
    }
}

/********************************************************************************************/




