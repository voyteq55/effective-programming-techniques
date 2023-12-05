#include "Node.h"
#include <string>
#include <deque>

Node::Node() {
    displayLabel = "";
    numberOfArguments = 0;
    childNodes = nullptr;
}

Node::Node(const Node &copy) {
    displayLabel = copy.displayLabel;
    numberOfArguments = copy.numberOfArguments;
    if (copy.childNodes == nullptr) {
        childNodes = nullptr;
    } else {
        childNodes = new Node*[numberOfArguments];
        for (int i = 0; i < numberOfArguments; i++) {
            childNodes[i] = copy.childNodes[i]->clone();
        }
    }
}

Node& Node::operator=(const Node &other) {
    if (childNodes != nullptr) {
        for (int i = 0; i < numberOfArguments; i++) {
            delete childNodes[i];
        }
        delete[] childNodes;
    }
    
    displayLabel = other.displayLabel;
    numberOfArguments = other.numberOfArguments;
    if (other.childNodes == nullptr) {
        childNodes = nullptr;
    } else {
        childNodes = new Node*[numberOfArguments];
        for (int i = 0; i < numberOfArguments; i++) {
//            childNodes[i] = new Node;
            childNodes[i] = other.childNodes[i]->clone();
        }
    }
    
    return *this;
}

Node::~Node() {
    for (int i = 0; i < numberOfArguments; i++) {
        delete childNodes[i];
    }
    delete[] childNodes;
}

void Node::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames) {}

void Node::addVariableNames(std::set<std::string> *variableNames) const {}

std::string Node::toStringWithChildren() const {
    return displayLabel;
}

std::string Node::toString() const {
    return displayLabel;
}

void Node::joinNode(Node *nodeToJoin) {}

bool Node::hasChildren() {
    return childNodes != nullptr;
}

void Node::setChildNode(int index, Node *node) {
    childNodes[index] = node;
}
