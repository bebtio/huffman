//
//  leafnode.hpp
//  huffmanEncoding
//
//  Created by Alberto Heras on 2/8/16.
//
//

#ifndef leafnode_hpp
#define leafnode_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#define LEFT_NODE true
#define RIGHT_NODE false
class leafnode
{
public:
    
    leafnode(leafnode* left, leafnode* right);
    leafnode(std::string c, int w);
    leafnode();
    ~leafnode();
    
    void printLeaf();
    
    std::string getSymbol() {return(this->symbol);}
    int getWeight() {return(this->weight);}
    void setParentNode(leafnode* parent) { this->parent = parent; }
    leafnode* getParentNode() { return(this->parent); }
    void setEncoding(std::string encoding) { this->encoding = encoding; }
    std::string getEncoding() {return(this->encoding);}
    std::string getEncodingSymbol() { return(this->encoding_symbol);}
    void createEncodingSymbol();
    
    
private:

    std::string encoding_symbol;
    std::string encoding;
    std::string symbol;
    int weight;
    leafnode *leftChild;
    leafnode *rightChild;
    leafnode *parent;
    
};

#endif /* leafnode_hpp */
