#include "PlusOperatorNode.h"
#include "OperatorConstants.h"
#include "Valuation.h"

PlusOperatorNode::PlusOperatorNode() {
    displayLabel = PLUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = PLUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

double PlusOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) + childNodes[1]->evaluate(valuation);
}

