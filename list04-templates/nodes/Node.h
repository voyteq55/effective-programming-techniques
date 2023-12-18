#ifndef NODE_H
#define NODE_H

#include <string>
#include <deque>
#include <set>
#include "Valuation.h"
#include "WarningNotifier.h"

class Node {
public:
    Node();
    Node(const Node &copy);
    
    Node& operator=(const Node &other);
    virtual Node* clone() const = 0;
    void makeCopy(const Node &other);
    
    virtual ~Node();
    
    virtual double evaluate(const Valuation& valuation) const = 0;
    virtual void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier);
    virtual void addVariableNames(std::set<std::string>* variableNames) const;
    virtual std::string toString() const;
    virtual std::string toStringWithChildren() const;
    virtual void joinNode(Node *nodeToJoin);
    bool hasChildren();
    void setChildNode(int index, Node *node);
    virtual Node* cloneChildren(Node *newNode) const;
    
protected:
    std::string displayLabel;
    int numberOfArguments;
    Node **childNodes;
    
    void deallocateMemory();
    
};

Node::Node() {
    displayLabel = "";
    numberOfArguments = 0;
    childNodes = nullptr;
}

Node::Node(const Node &copy) {
    makeCopy(copy);
}

Node& Node::operator=(const Node &other) {
    if (this != &other) {
        if (childNodes != nullptr) {
            deallocateMemory();
        }
        makeCopy(other);
    }
    return *this;
}

void Node::makeCopy(const Node &other) {
    displayLabel = other.displayLabel;
    numberOfArguments = other.numberOfArguments;
    if (other.childNodes == nullptr) {
        childNodes = nullptr;
    } else {
        childNodes = new Node*[numberOfArguments];
        for (int i = 0; i < numberOfArguments; i++) {
            childNodes[i] = other.childNodes[i]->clone();
        }
    }
}

Node::~Node() {
    deallocateMemory();
}

void Node::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) {}

void Node::addVariableNames(std::set<std::string> *variableNames) const {}

std::string Node::toString() const {
    return displayLabel;
}

std::string Node::toStringWithChildren() const {
    return toString();
}

void Node::joinNode(Node *nodeToJoin) {}

bool Node::hasChildren() {
    return childNodes != nullptr;
}

void Node::setChildNode(int index, Node *node) {
    childNodes[index] = node;
}

Node* Node::cloneChildren(Node *newNode) const {
    for (int i = 0; i < numberOfArguments; i++) {
        newNode->setChildNode(i, childNodes[i]->clone());
    }
    return newNode;
}

void Node::deallocateMemory() {
    for (int i = 0; i < numberOfArguments; i++) {
        delete childNodes[i];
    }
    delete[] childNodes;
}


#endif
