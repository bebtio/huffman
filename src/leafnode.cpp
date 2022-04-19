//
//  leafnode.cpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/8/16.
//
//


#include "leafnode.h"
#include <algorithm>
/*************************************************************************************/

leafnode::leafnode(leafnode* left, leafnode* right)
{
    this->weight = left->weight + right->weight;
    
    this->leftChild = left;

    this->leftChild->setEncoding("0");
    this->leftChild->setParentNode(this);
    
    this->rightChild= right;
    this->rightChild->setEncoding("1");
    this->rightChild->setParentNode(this);
    this->parent = NULL;
    
    this->symbol = left->symbol + " " + right->symbol;



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
    this->encoding ="";
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
    std::cout << "The letters: "<<this->symbol << " Weight: " << this->weight << std::endl;
}

/*************************************************************************************/

void leafnode::createEncodingSymbol()
{
    leafnode *tempNode = this;
    
    std::cout << tempNode->getSymbol() << std::endl;

    while(tempNode->parent != NULL)
    {
        tempNode = tempNode->parent;

        this->encoding.append(tempNode->encoding);
        std::cout << this->encoding << std::endl;
    }
    
    std::cout << std::endl;
    std::reverse(this->encoding.begin(), this->encoding.end());
}
