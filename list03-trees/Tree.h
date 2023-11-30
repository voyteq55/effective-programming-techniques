#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <string>
#include <deque>

class Tree {
public:
    Tree();
    
    ~Tree();
    
    void enterNewTree(std::deque<std::string>& userArgs);
    std::string toPrefixNotation();
    void joinTree(std::deque<std::string>& userArgs);
    
private:
    Node* rootNode;
};

#endif
