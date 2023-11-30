#include "Tree.h"
#include "NodeCreator.h"

Tree::Tree(): rootNode(nullptr) {}

Tree::~Tree() {
    delete rootNode;
}

void Tree::enterNewTree(std::deque<std::string> &userArgs) {
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    rootNode = NodeCreator::allocateAndReturnPointer(nextArg);
    rootNode->createChildren(userArgs);
}

std::string Tree::toPrefixNotation() {
    if (rootNode != nullptr) {
        return rootNode->toStringWithChildren();
    } else {
        return "";
    }
}
