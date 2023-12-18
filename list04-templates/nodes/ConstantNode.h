#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "Node.h"
#include <string>

const int DEFAULT_CONSTANT_VALUE = 1;

class ConstantNode: public Node {
public:
    ConstantNode();
    ConstantNode(double value);
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const double constantValue;
    
};

ConstantNode::ConstantNode(): constantValue(DEFAULT_CONSTANT_VALUE) {}

ConstantNode::ConstantNode(double value): constantValue(value) {}

Node* ConstantNode::clone() const {
    return new ConstantNode(constantValue);
}

double ConstantNode::evaluate(const Valuation &valuation) const {
    return constantValue;
}

std::string ConstantNode::toString() const {
    return std::to_string(static_cast<int>(constantValue));
}

std::string ConstantNode::toStringWithChildren() const {
    return toString();
}

#endif
