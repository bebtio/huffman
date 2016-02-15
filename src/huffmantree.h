//
//  huffmantree.hpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/12/16.
//
//

#ifndef huffmantree_h
#define huffmantree_h

#include <stdio.h>
#include "leafnode.h"
#include <vector>
#include <queue>

class Compare
{
public:
    bool operator() (leafnode* a,leafnode* b)
    {
        return(a->getWeight() > b->getWeight());
    }
};

class huffmantree
{
public:
    
    huffmantree(std::vector<std::pair<std::string, int > > input);
    huffmantree();
    ~huffmantree();
    
    void createLeafNodes(std::vector<std::pair<std::string, int> > charCount);
    void printHuffmanTree();
    void printLeafNodes();
    void addLeafNode(leafnode* leaf) { this->leaves.push_back(leaf); }
    void printEncodings();
    
    std::string getEncoding(char letter);
    
    
private:
    
    void createHuffmanTree();

    void generateEncodings();
    
    std::vector<leafnode*> leaves;
    std::priority_queue<leafnode*,std::vector<leafnode*>, Compare >tree;
};



#endif /* huffmantree_h */


