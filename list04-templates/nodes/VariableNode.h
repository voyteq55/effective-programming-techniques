#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "Node.h"
#include <string>

class VariableNode: public Node {
public:
    VariableNode();
    VariableNode(const std::string variableName);
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const std::string variableName;
    
};

VariableNode::VariableNode(): variableName() {}

VariableNode::VariableNode(const std::string variableName): variableName(variableName) {}

Node* VariableNode::clone() const {
    return new VariableNode(variableName);
}

double VariableNode::evaluate(const Valuation &valuation) const {
    return valuation.evaluateVariable(variableName);
}

void VariableNode::createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) {
    addVariableNames(variableNames);
}

void VariableNode::addVariableNames(std::set<std::string> *variableNames) const {
    variableNames->insert(variableName);
}

std::string VariableNode::toString() const {
    return variableName;
}

std::string VariableNode::toStringWithChildren() const {
    return toString();
}

#endif
