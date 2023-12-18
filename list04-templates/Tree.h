#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "OperatorNode.h"
#include <string>
#include <deque>
#include <set>

const std::string EMPTY_TREE_REPRESENTATION = "<empty tree>";

template <typename T>
class Tree {
public:
    Tree();
    Tree(const Tree<T> &copy);
    
    Tree<T>& operator=(const Tree<T> &other);
    void makeCopy(const Tree<T> &other);
    
    Tree<T> operator+(const Tree<T> &other) const;
    
    ~Tree();
    
    void enterNewTree(std::deque<std::string>& userArgs, WarningNotifier &warningNotifier);
    std::string toPrefixNotation();
    double evaluate(const Valuation<T> &valuation);
    void joinTree(std::deque<std::string>& userArgs, WarningNotifier &warningNotifier);
    void joinAndUpdateVariableNames(Node<T> *newRootNode);
    std::string getVariableNamesString();
    std::set<std::string>* getVariableNamesSet() const;
    
private:
    Node<T> *rootNode;
    std::set<std::string> *variableNames;
    
    void joinNode(Node<T> *otherRootNode);
    void deallocateMemory();
};

template <typename T>
Tree<T>::Tree(): rootNode(nullptr) {
    variableNames = new std::set<std::string>;
}

template <typename T>
Tree<T>::Tree(const Tree<T> &copy) {
    makeCopy(copy);
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree<T> &other) {
    if (this != &other) {
        deallocateMemory();
        makeCopy(other);
    }
    return *this;
}

template <typename T>
void Tree<T>::makeCopy(const Tree<T> &other) {
    rootNode = other.rootNode->clone();
    variableNames = new std::set<std::string>(*other.variableNames);
}

template <typename T>
Tree<T>::~Tree() {
    deallocateMemory();
}

template <typename T>
void Tree<T>::enterNewTree(std::deque<std::string> &userArgs, WarningNotifier &warningNotifier) {
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
    rootNode = OperatorNode<T>::allocateAndReturnPointer(nextArg);
    rootNode->createChildren(userArgs, variableNames, warningNotifier);
    
    if (!userArgs.empty()) {
        warningNotifier.notifyEnterTooManyNodes(userArgs);
    }
}

template <typename T>
std::string Tree<T>::toPrefixNotation() {
    if (rootNode != nullptr) {
        return rootNode->toStringWithChildren();
    }
    return EMPTY_TREE_REPRESENTATION;
}

template <typename T>
double Tree<T>::evaluate(const Valuation<T> &valuation) {
    if (rootNode != nullptr) {
        return rootNode->evaluate(valuation);
    }
    return 0;
}

template <typename T>
void Tree<T>::joinTree(std::deque<std::string> &userArgs, WarningNotifier &warningNotifier) {
    if (userArgs.empty()) {
        return;
    }
    Node<T> *newRootNode;
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    newRootNode = OperatorNode<T>::allocateAndReturnPointer(nextArg);
    newRootNode->createChildren(userArgs, variableNames, warningNotifier);
    
    if (!userArgs.empty()) {
        warningNotifier.notifyEnterTooManyNodes(userArgs);
    }
    
    joinAndUpdateVariableNames(newRootNode);
}

template <typename T>
Tree<T> Tree<T>::operator+(const Tree<T> &other) const {
    Tree<T> resultTree(*this);
    Node<T>* newRootNode = other.rootNode->clone();
    
    resultTree.joinAndUpdateVariableNames(newRootNode);
    
    return resultTree;
}

template <typename T>
inline void Tree<T>::joinAndUpdateVariableNames(Node<T> *newRootNode) {
    joinNode(newRootNode);
    variableNames->clear();
    rootNode->addVariableNames(variableNames);
}

template <typename T>
std::string Tree<T>::getVariableNamesString() {
    std::string allVariableNames;
    for (const std::string& name : *variableNames) {
        allVariableNames += name;
        allVariableNames += " ";
    }
    return allVariableNames;
}

template <typename T>
std::set<std::string>* Tree<T>::getVariableNamesSet() const {
    return variableNames;
}

template <typename T>
void Tree<T>::joinNode(Node<T> *otherRootNode) {
    if (rootNode == nullptr) {
        rootNode = otherRootNode;
    } else if (!rootNode->hasChildren()) {
        delete rootNode;
        rootNode = otherRootNode;
    } else {
        rootNode->joinNode(otherRootNode);
    }
}

template <typename T>
void Tree<T>::deallocateMemory() {
    delete rootNode;
    delete variableNames;
}

#endif
