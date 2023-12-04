#include "ConstantNode.h"

ConstantNode::ConstantNode(): constantValue(DEFAULT_CONSTANT_VALUE) {}

ConstantNode::ConstantNode(double value): constantValue(value) {
//    displayLabel = std::to_string(constantValue);
}

double ConstantNode::evaluate(const Valuation &valuation) const {
    return constantValue;
}

std::string ConstantNode::toString() const {
    return std::to_string(constantValue);
}

std::string ConstantNode::toStringWithChildren() const {
    return toString();
}
