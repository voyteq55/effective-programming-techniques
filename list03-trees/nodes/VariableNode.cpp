#include "VariableNode.h"

VariableNode::VariableNode(): variableName() {}

VariableNode::VariableNode(const std::string variableName): variableName(variableName) {}

double VariableNode::evaluate(const Valuation &valuation) const {
    return valuation.evaluateVariable(variableName);
}

void VariableNode::createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames) {
    variableNames->insert(variableName);
}

std::string VariableNode::toString() const {
    return variableName;
}

std::string VariableNode::toStringWithChildren() const {
    return toString();
}


