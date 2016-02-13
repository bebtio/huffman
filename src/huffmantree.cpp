//
//  huffmantree.cpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/12/16.
//
//



#include "huffmantree.h"

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
        
        std::cout << i->getSymbol() << " " << i->getWeight() << std::endl;
        tree.push(i);
        
        this->printLeafNodes();
        
    }
}

/********************************************************************************************/

void huffmantree::printHuffmanTree()
{
    for(int i = 0; i < this->leaves.size(); i++)
    {
        leaves.at(i)->printLeaf();
        std::cout << leaves.at(i)->getEncoding() << " " << leaves.at(i)->getEncodingSymbol() <<std::endl << std::endl;;
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

void huffmantree::printLeafNodes()
{
    for(int i = 0; i < this->leaves.size(); i++)
    {
    
    }
}