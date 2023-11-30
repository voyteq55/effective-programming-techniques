#ifndef PLUSOPERATORNODE_H
#define PLUSOPERATORNODE_H

#include "OperatorNode.h"

class PlusOperatorNode: public OperatorNode {
public:
    PlusOperatorNode();
    
    double evaluate(const Valuation &valuation) const override;
};

#endif
