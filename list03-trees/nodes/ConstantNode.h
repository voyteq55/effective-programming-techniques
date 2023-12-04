#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "Node.h"
//#include "Valuation.h"
#include <string>

const int DEFAULT_CONSTANT_VALUE = 1;

class ConstantNode: public Node {
public:
    ConstantNode();
    ConstantNode(double value);
    
    double evaluate(const Valuation &valuation) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const double constantValue;
    
};

#endif
