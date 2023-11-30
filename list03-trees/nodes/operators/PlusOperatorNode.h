#ifndef PLUSOPERATORNODE_H
#define PLUSOPERATORNODE_H

#include "OperatorNode.h"

const std::string PLUS_OPERATOR_DISPLAY_LABEL = "+";

const int PLUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;

class PlusOperatorNode: public OperatorNode {
public:
    PlusOperatorNode();
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
