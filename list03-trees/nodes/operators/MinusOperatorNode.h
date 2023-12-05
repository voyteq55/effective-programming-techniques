#ifndef MINUSOPERATORNODE_H
#define MINUSOPERATORNODE_H

#include "OperatorNode.h"

const std::string MINUS_OPERATOR_DISPLAY_LABEL = "-";

const int MINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;

class MinusOperatorNode: public OperatorNode {
public:
    MinusOperatorNode();
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
