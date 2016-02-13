//
//  leafnode.cpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/8/16.
//
//


#include "leafnode.h"

/*************************************************************************************/

leafnode::leafnode(leafnode* left, leafnode* right)
{
    this->weight = left->weight + right->weight;
    
    this->leftChild = left;
    std::string encode = this->encoding + '0';
    this->leftChild->setEncoding(this->encoding + '0');
    this->leftChild->setParentNode(this);
    
    this->rightChild= right;
    this->rightChild->setEncoding(this->encoding + '1');
    this->rightChild->setParentNode(this);
    this->parent = NULL;
    
    this->symbol = left->symbol + " " + right->symbol;
    this->encoding_symbol = "";
}


/*************************************************************************************/

leafnode::leafnode(std::string c, int w)
{
    this->symbol = c;
    this->weight = w;
    this->rightChild = NULL;
    this->parent = NULL;
    this->leftChild = NULL;
    this->encoding_symbol = "";
}

/*************************************************************************************/

leafnode::leafnode()
{
    this->encoding_symbol = "";
    this->encoding= 2;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->parent = NULL;
}

/*************************************************************************************/

leafnode::~leafnode()
{
    
}

/*************************************************************************************/

void leafnode::printLeaf()
{
    std::cout << "The letters: "<<this->symbol << " Wieght: " << this->weight << std::endl;
}

/*************************************************************************************/

void leafnode::createEncodingSymbol()
{
    leafnode *tempNode = this;
    
    while(tempNode->parent != NULL)
    {
        tempNode = tempNode->parent;

        this->encoding.append(tempNode->encoding);
    }
}
