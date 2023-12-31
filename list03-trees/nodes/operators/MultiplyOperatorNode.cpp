#include "MultiplyOperatorNode.h"

MultiplyOperatorNode::MultiplyOperatorNode() {
    displayLabel = MULTIPLY_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* MultiplyOperatorNode::clone() const {
    Node* newNode = new MultiplyOperatorNode();
    return cloneChildren(newNode);
}

double MultiplyOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) * childNodes[1]->evaluate(valuation);
}
