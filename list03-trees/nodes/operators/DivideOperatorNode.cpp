#include "DivideOperatorNode.h"

DivideOperatorNode::DivideOperatorNode() {
    displayLabel = DIVIDE_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

double DivideOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) / childNodes[1]->evaluate(valuation);
}
