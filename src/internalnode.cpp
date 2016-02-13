//
//  internalnode.cpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/8/16.
//
//

#include "internalnode.h"

internalnode::internalnode(internalnode *p,leafnode* l, leafnode* r, int w)
{
    this->parent = p;
    this->leftChild = l;
    this->rightChild = r;
    this->weight = w;
}

internalnode::internalnode()
{
    this->parent = NULL;
    this->leftChild = NULL;
    this->rightChild = NULL;
    
}

internalnode::~internalnode()
{
    
}