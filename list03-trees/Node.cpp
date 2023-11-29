#include "Node.h"

Node::Node() {
    displayLabel = "";
}

Node::~Node() {}

std::string Node::toString() {
    return displayLabel;
}
