#include "MinusOperatorNode.h"

MinusOperatorNode::MinusOperatorNode() {
    displayLabel = MINUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = MINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

double MinusOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) - childNodes[1]->evaluate(valuation);
}
