#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "OperatorNode.h"
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
    
    void enterNewTree(std::deque<std::string>& userArgs, WarningNotifier &warningNotifier);
    std::string toPrefixNotation();
    double evaluate(const Valuation &valuation);
    void joinTree(std::deque<std::string>& userArgs, WarningNotifier &warningNotifier);
    void joinAndUpdateVariableNames(Node *newRootNode);
    std::string getVariableNamesString();
    std::set<std::string>* getVariableNamesSet() const;
    
private:
    Node *rootNode;
    std::set<std::string> *variableNames;
    
    void joinNode(Node *otherRootNode);
    void deallocateMemory();
};

Tree::Tree(): rootNode(nullptr) {
    variableNames = new std::set<std::string>;
}

Tree::Tree(const Tree &copy) {
    makeCopy(copy);
}

Tree& Tree::operator=(const Tree &other) {
    if (this != &other) {
        deallocateMemory();
        makeCopy(other);
    }
    return *this;
}

void Tree::makeCopy(const Tree &other) {
    rootNode = other.rootNode->clone();
    variableNames = new std::set<std::string>(*other.variableNames);
}

Tree::~Tree() {
    deallocateMemory();
}

void Tree::enterNewTree(std::deque<std::string> &userArgs, WarningNotifier &warningNotifier) {
    if (userArgs.empty()) {
        deallocateMemory();
        rootNode = nullptr;
        variableNames = new std::set<std::string>;
        return;
    }
    deallocateMemory();
    variableNames = new std::set<std::string>;
    
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    rootNode = OperatorNode::allocateAndReturnPointer(nextArg);
    rootNode->createChildren(userArgs, variableNames, warningNotifier);
    
    if (!userArgs.empty()) {
        warningNotifier.notifyEnterTooManyNodes(userArgs);
    }
}

std::string Tree::toPrefixNotation() {
    if (rootNode != nullptr) {
        return rootNode->toStringWithChildren();
    }
    return EMPTY_TREE_REPRESENTATION;
}

double Tree::evaluate(const Valuation &valuation) {
    if (rootNode != nullptr) {
        return rootNode->evaluate(valuation);
    }
    return 0;
}

void Tree::joinTree(std::deque<std::string> &userArgs, WarningNotifier &warningNotifier) {
    if (userArgs.empty()) {
        return;
    }
    Node *newRootNode;
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    newRootNode = OperatorNode::allocateAndReturnPointer(nextArg);
    newRootNode->createChildren(userArgs, variableNames, warningNotifier);
    
    if (!userArgs.empty()) {
        warningNotifier.notifyEnterTooManyNodes(userArgs);
    }
    
    joinAndUpdateVariableNames(newRootNode);
}

Tree Tree::operator+(const Tree &other) const {
    Tree resultTree(*this);
    Node* newRootNode = other.rootNode->clone();
    
    resultTree.joinAndUpdateVariableNames(newRootNode);
    
    return resultTree;
}

inline void Tree::joinAndUpdateVariableNames(Node *newRootNode) {
    joinNode(newRootNode);
    variableNames->clear();
    rootNode->addVariableNames(variableNames);
}

std::string Tree::getVariableNamesString() {
    std::string allVariableNames;
    for (const std::string& name : *variableNames) {
        allVariableNames += name;
        allVariableNames += " ";
    }
    return allVariableNames;
}

std::set<std::string>* Tree::getVariableNamesSet() const {
    return variableNames;
}

void Tree::joinNode(Node *otherRootNode) {
    if (rootNode == nullptr) {
        rootNode = otherRootNode;
    } else if (!rootNode->hasChildren()) {
        delete rootNode;
        rootNode = otherRootNode;
    } else {
        rootNode->joinNode(otherRootNode);
    }
}

void Tree::deallocateMemory() {
    delete rootNode;
    delete variableNames;
}

#endif
