#include "Tree.h"
#include "NodeCreator.h"

#include <iostream>

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

void Tree::enterNewTree(std::deque<std::string> &userArgs) {
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
    rootNode = NodeCreator::allocateAndReturnPointer(nextArg);
    rootNode->createChildren(userArgs, variableNames);
}

std::string Tree::toPrefixNotation() {
    if (rootNode != nullptr) {
        return rootNode->toStringWithChildren();
    }
    return EMPTY_TREE_REPRESENTATION;
}

double Tree::evaluate(const Valuation &valuation) {
    return rootNode->evaluate(valuation);
}

void Tree::joinTree(std::deque<std::string> &userArgs) {
    if (userArgs.empty()) {
        return;
    }
    Node *newRootNode;
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    newRootNode = NodeCreator::allocateAndReturnPointer(nextArg);
    newRootNode->createChildren(userArgs, variableNames);
    
    
    joinNode(newRootNode);
    
    variableNames->clear();
    rootNode->addVariableNames(variableNames);
}

Tree Tree::operator+(const Tree &other) const {
    Tree resultTree(*this);
//    Node* newRootNode = other.rootNode->clone();
//    
//    //do wydzielenia
//    resultTree.joinNode(newRootNode);
//    
//    resultTree.variableNames->clear();
//    resultTree.rootNode->addVariableNames(resultTree.variableNames);
    
    
    return resultTree;
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
