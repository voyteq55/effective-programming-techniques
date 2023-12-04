#include "Tree.h"
#include "NodeCreator.h"

Tree::Tree(): rootNode(nullptr) {
    variableNames = new std::set<std::string>;
}

Tree::~Tree() {
    deallocateMemory();
}

void Tree::enterNewTree(std::deque<std::string> &userArgs) {
    deallocateMemory();
    variableNames = new std::set<std::string>;
    
    std::string nextArg = userArgs.front();
    userArgs.pop_front();
    rootNode = NodeCreator::allocateAndReturnPointer(nextArg);
    rootNode->createChildren(userArgs, variableNames);
}

std::string Tree::toPrefixNotation() {
    if (rootNode != nullptr) {
        return rootNode->toStringWithChildren();
    }
    return "";
}

double Tree::evaluate(const Valuation &valuation) {
    return rootNode->evaluate(valuation);
}

std::string Tree::getVariableNames() {
    std::string allVariableNames;
    for (const std::string& name : *variableNames) {
        allVariableNames += name;
        allVariableNames += ", ";
    }
    return allVariableNames;
}

void Tree::deallocateMemory() {
    delete rootNode;
    delete variableNames;
}
