#include "MinusOperatorNode.h"

MinusOperatorNode::MinusOperatorNode() {
    displayLabel = MINUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = MINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* MinusOperatorNode::clone() const {
    Node* newNode = new MinusOperatorNode();
    for (int i = 0; i < numberOfArguments; i++) {
        newNode->setChildNode(i, childNodes[i]->clone());
    }
    return newNode;
}

double MinusOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) - childNodes[1]->evaluate(valuation);
}
