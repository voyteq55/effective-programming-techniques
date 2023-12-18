#ifndef COSINUSOPERATORNODE_H
#define COSINUSOPERATORNODE_H

#include "OperatorNode.h"

const std::string COSINUS_OPERATOR_DISPLAY_LABEL = "cos";

const int COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;

class CosinusOperatorNode: public OperatorNode {
public:
    CosinusOperatorNode();
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
