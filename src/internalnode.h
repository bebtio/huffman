//
//  internalnode.hpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/8/16.
//
//

#ifndef internalnode_hpp
#define internalnode_hpp

#include <stdio.h>
#include "leafnode.h"

class leafnode;

class internalnode
{
public:
    internalnode(internalnode *p,leafnode* l, leafnode* r, int w);
    internalnode();
    ~internalnode();
    
private:
    int weight;
    leafnode* leftChild;
    leafnode* rightChild;
    internalnode* parent;
    
};

#endif /* internalnode_hpp */
