#include "SinusOperatorNode.h"
#include <cmath>

SinusOperatorNode::SinusOperatorNode() {
    displayLabel = SINUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = SINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* SinusOperatorNode::clone() const {
    Node* newNode = new SinusOperatorNode();
    return cloneChildren(newNode);
}

double SinusOperatorNode::evaluate(const Valuation &valuation) const {
    return std::sin(childNodes[0]->evaluate(valuation) * M_PI / 180.0) ;
}
