#include "PlusOperatorNode.h"

PlusOperatorNode::PlusOperatorNode() {
    displayLabel = PLUS_OPERATOR_DISPLAY_LABEL;
    numberOfArguments = PLUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* PlusOperatorNode::clone() const {
    Node* newNode = new PlusOperatorNode();
    for (int i = 0; i < numberOfArguments; i++) {
        newNode->setChildNode(i, childNodes[i]->clone());
    }
    return newNode;
}

double PlusOperatorNode::evaluate(const Valuation &valuation) const {
    return childNodes[0]->evaluate(valuation) + childNodes[1]->evaluate(valuation);
}
