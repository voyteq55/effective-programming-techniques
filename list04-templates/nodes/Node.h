#ifndef NODE_H
#define NODE_H

#include <string>
#include <deque>
#include <set>
#include "Valuation.h"
#include "WarningNotifier.h"

template <typename T>
class Node {
public:
    Node();
    Node(const Node<T> &copy);
    
    Node<T>& operator=(const Node<T> &other);
    virtual Node<T>* clone() const = 0;
    void makeCopy(const Node<T> &other);
    
    virtual ~Node();
    
    virtual T evaluate(const Valuation<T>& valuation) const = 0;
    virtual void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier);
    virtual void addVariableNames(std::set<std::string>* variableNames) const;
    virtual std::string toString() const;
    virtual std::string toStringWithChildren() const;
    virtual void joinNode(Node<T> *nodeToJoin);
    bool hasChildren();
    void setChildNode(int index, Node<T> *node);
    virtual Node<T>* cloneChildren(Node<T> *newNode) const;
    
protected:
    std::string displayLabel;
    int numberOfArguments;
    Node<T> **childNodes;
    
    void deallocateMemory();
    
};

template <typename T>
Node<T>::Node() {
    displayLabel = "";
    numberOfArguments = 0;
    childNodes = nullptr;
}

template <typename T>
Node<T>::Node(const Node<T> &copy) {
    makeCopy(copy);
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T> &other) {
    if (this != &other) {
        if (childNodes != nullptr) {
            deallocateMemory();
        }
        makeCopy(other);
    }
    return *this;
}

template <typename T>
void Node<T>::makeCopy(const Node<T> &other) {
    displayLabel = other.displayLabel;
    numberOfArguments = other.numberOfArguments;
    if (other.childNodes == nullptr) {
        childNodes = nullptr;
    } else {
        childNodes = new Node<T>*[numberOfArguments];
        for (int i = 0; i < numberOfArguments; i++) {
            childNodes[i] = other.childNodes[i]->clone();
        }
    }
}

template <typename T>
Node<T>::~Node() {
    deallocateMemory();
}

template <typename T>
void Node<T>::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) {}

template <typename T>
void Node<T>::addVariableNames(std::set<std::string> *variableNames) const {}

template <typename T>
std::string Node<T>::toString() const {
    return displayLabel;
}

template <typename T>
std::string Node<T>::toStringWithChildren() const {
    return toString();
}

template <typename T>
void Node<T>::joinNode(Node<T> *nodeToJoin) {}

template <typename T>
bool Node<T>::hasChildren() {
    return childNodes != nullptr;
}

template <typename T>
void Node<T>::setChildNode(int index, Node<T> *node) {
    childNodes[index] = node;
}

template <typename T>
Node<T>* Node<T>::cloneChildren(Node<T> *newNode) const {
    for (int i = 0; i < numberOfArguments; i++) {
        newNode->setChildNode(i, childNodes[i]->clone());
    }
    return newNode;
}

template <typename T>
void Node<T>::deallocateMemory() {
    for (int i = 0; i < numberOfArguments; i++) {
        delete childNodes[i];
    }
    delete[] childNodes;
}

#endif
