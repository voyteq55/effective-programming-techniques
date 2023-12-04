#include "Node.h"
#include <string>
#include <deque>

Node::Node() {
    displayLabel = "";
    numberOfArguments = 0;
    childNodes = nullptr;
}

Node::~Node() {}

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
