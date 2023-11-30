#include "Node.h"
#include <string>
#include <deque>

Node::Node() {
    displayLabel = "";
}

Node::~Node() {}

void Node::createChildren(std::deque<std::string> &userArgs) {}

std::string Node::toStringWithChildren() const {
    return "";
}

std::string Node::toString() const {
    return displayLabel;
}
