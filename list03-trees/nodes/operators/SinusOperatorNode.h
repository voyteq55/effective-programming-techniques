#ifndef SINUSOPERATORNODE_H
#define SINUSOPERATORNODE_H

#include "OperatorNode.h"

const std::string SINUS_OPERATOR_DISPLAY_LABEL = "sin";

const int SINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;

class SinusOperatorNode: public OperatorNode {
public:
    SinusOperatorNode();
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
};

#endif

