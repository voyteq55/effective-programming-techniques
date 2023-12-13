#include "CosinusOperatorNode.h"
#include <cmath>

CosinusOperatorNode::CosinusOperatorNode() {
    displayLabel = COSINUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* CosinusOperatorNode::clone() const {
    Node* newNode = new CosinusOperatorNode();
    return cloneChildren(newNode);
}

double CosinusOperatorNode::evaluate(const Valuation &valuation) const {
    return std::cos(childNodes[0]->evaluate(valuation) * M_PI / 180.0) ;
}
