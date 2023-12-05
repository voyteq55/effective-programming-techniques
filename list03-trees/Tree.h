#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <string>
#include <deque>
#include <set>

const std::string EMPTY_TREE_REPRESENTATION = "<empty tree>";

class Tree {
public:
    Tree();
    Tree(const Tree &copy);
    
    Tree& operator=(const Tree &other);
    void makeCopy(const Tree &other);
    
    Tree operator+(const Tree &other) const;
    
    ~Tree();
    
    void enterNewTree(std::deque<std::string>& userArgs);
    std::string toPrefixNotation();
    double evaluate(const Valuation &valuation);
    void joinTree(std::deque<std::string>& userArgs);
    std::string getVariableNamesString();
    std::set<std::string>* getVariableNamesSet() const;
    
private:
    Node *rootNode;
    std::set<std::string> *variableNames;
    
    void joinNode(Node *otherRootNode);
    void deallocateMemory();
};

#endif
