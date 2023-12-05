#include "OperatorNode.h"
#include "NodeCreator.h"

OperatorNode::OperatorNode() {
    numberOfArguments = 0;
}

void OperatorNode::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames) {
    for (int i = 0; i < numberOfArguments; i++) {
        if (!userArgs.empty()) {
            std::string argString = userArgs.front();
            userArgs.pop_front();
            childNodes[i] = NodeCreator::allocateAndReturnPointer(argString);
            childNodes[i]->createChildren(userArgs, variableNames);
        } else {
            childNodes[i] = NodeCreator::allocateDefaultConstantNode();
        }
    }
}

void OperatorNode::addVariableNames(std::set<std::string> *variableNames) const {
    for (int i = 0; i < numberOfArguments; i++) {
        childNodes[i]->addVariableNames(variableNames);
    }
}

std::string OperatorNode::toString() const {
    return displayLabel;
}

std::string OperatorNode::toStringWithChildren() const {
    std::string stringToReturn = displayLabel;
    for (int i = 0; i < numberOfArguments; i++) {
        stringToReturn += " ";
        stringToReturn += childNodes[i]->toStringWithChildren();
    }
    return stringToReturn;
}

void OperatorNode::joinNode(Node *nodeToJoin) {
    Node *firstChild = childNodes[0];
    if (firstChild->hasChildren()) {
        firstChild->joinNode(nodeToJoin);
    } else {
        delete firstChild;
        childNodes[0] = nodeToJoin;
    }
}
