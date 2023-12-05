#include "Node.h"
#include <string>
#include <deque>

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

void Node::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames) {}

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

void Node::deallocateMemory() {
    for (int i = 0; i < numberOfArguments; i++) {
        delete childNodes[i];
    }
    delete[] childNodes;
}
