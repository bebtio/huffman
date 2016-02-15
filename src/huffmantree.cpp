//
//  huffmantree.cpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/12/16.
//
//



#include "huffmantree.h"
#include <sstream>
huffmantree::huffmantree(std::vector<std::pair<std::string, int > > input)
{
    this->createLeafNodes(input);
    this->createHuffmanTree();
    this->generateEncodings();
}


huffmantree::huffmantree()
{
   
}

huffmantree::~huffmantree()
{
    
}


/********************************************************************************************/

void huffmantree::createLeafNodes(std::vector<std::pair<std::string,int> > charCount)
{
    for(int i = 0; i < charCount.size(); i++)
    {
        leafnode *tempLeaf = new leafnode(charCount.at(i).first,charCount.at(i).second);
                
        this->tree.push(tempLeaf);
        this->leaves.push_back(tempLeaf);
    }
    
    this->createHuffmanTree();
    this->generateEncodings();
}

/********************************************************************************************/

void huffmantree::createHuffmanTree()
{
    while(this->tree.size() > 1)
    {
        leafnode* l = this->tree.top();
        
        this->tree.pop();
        
        leafnode* r = this->tree.top();
        this->tree.pop();
        
        leafnode* i = new leafnode(l,r);
        
        tree.push(i);
    }
}

/********************************************************************************************/

void huffmantree::printHuffmanTree()
{
    std::cout << "Letter\t" << "Weight\t" << "Encoding\t" << std::endl;
    for(int i = 0; i < this->leaves.size(); i++)
    {
        std::cout << leaves.at(i)->getSymbol() << "\t\t";
        std::cout << leaves.at(i)->getWeight() << "\t\t";
        std::cout << leaves.at(i)->getEncoding() << "\t\t" << std::endl;;
    }
}

/********************************************************************************************/

void huffmantree::generateEncodings()
{
    for(int i = 0; i < this->leaves.size(); i ++)
    {
        this->leaves.at(i)->createEncodingSymbol();
    }
}

/********************************************************************************************/

std::string huffmantree::getEncoding(char letter)
{
    for(int i =  0; i < this->leaves.size(); i++)
    {
        std::string in = this->leaves.at(i)->getSymbol();
        std::stringstream ss;
        ss << letter;
        if(ss.str() == in)
        {
            return(this->leaves.at(i)->getEncoding());
        }
    }
    
    return("FAIL");
}
