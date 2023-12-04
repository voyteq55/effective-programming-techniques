#ifndef MULTIPLYOPERATORNODE_H
#define MULTIPLYOPERATORNODE_H

#include "OperatorNode.h"

const std::string MULTIPLY_OPERATOR_DISPLAY_LABEL = "*";

const int MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS = 2;

class MultiplyOperatorNode: public OperatorNode {
public:
    MultiplyOperatorNode();
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
