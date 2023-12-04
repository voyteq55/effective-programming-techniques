#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <string>
#include <deque>
#include <set>

class Tree {
public:
    Tree();
    
    ~Tree();
    
    void enterNewTree(std::deque<std::string>& userArgs);
    std::string toPrefixNotation();
    double evaluate(const Valuation &valuation);
    void joinTree(std::deque<std::string>& userArgs);
    std::string getVariableNames();
    
private:
    Node* rootNode;
    std::set<std::string>* variableNames;
    
    void deallocateMemory();
};

#endif
