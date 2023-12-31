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

#endif
