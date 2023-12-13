#ifndef DIVIDEOPERATORNODE_H
#define DIVIDEOPERATORNODE_H

#include "OperatorNode.h"

const std::string DIVIDE_OPERATOR_DISPLAY_LABEL = "/";

const int DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS = 2;

class DivideOperatorNode: public OperatorNode {
public:
    DivideOperatorNode();
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
