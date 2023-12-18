#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"
#include "ConstantNode.h"
#include "VariableNode.h"

const std::string DEFAULT_VARIABLE_FIRST_LETTER = "A";

const std::string PLUS_OPERATOR_DISPLAY_LABEL = "+";
const std::string MINUS_OPERATOR_DISPLAY_LABEL = "-";
const std::string MULTIPLY_OPERATOR_DISPLAY_LABEL = "*";
const std::string DIVIDE_OPERATOR_DISPLAY_LABEL = "/";
const std::string SINUS_OPERATOR_DISPLAY_LABEL = "sin";
const std::string COSINUS_OPERATOR_DISPLAY_LABEL = "cos";

const int PLUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int SINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;
const int COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;

class OperatorNode: public Node {
public:
    OperatorNode();
    OperatorNode(std::string displayLabel);
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    void joinNode(Node *nodeToJoin) override;
    
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();
    static void removeInvalidCharacters(std::string& userInput);
    
};

OperatorNode::OperatorNode() {
    numberOfArguments = 0;
}

OperatorNode::OperatorNode(std::string label) {
    displayLabel = label;
    if (displayLabel == PLUS_OPERATOR_DISPLAY_LABEL) numberOfArguments = PLUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (displayLabel == MINUS_OPERATOR_DISPLAY_LABEL) numberOfArguments = MINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (displayLabel == MULTIPLY_OPERATOR_DISPLAY_LABEL) numberOfArguments = MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (displayLabel == DIVIDE_OPERATOR_DISPLAY_LABEL) numberOfArguments = DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (displayLabel == SINUS_OPERATOR_DISPLAY_LABEL) numberOfArguments = SINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (displayLabel == COSINUS_OPERATOR_DISPLAY_LABEL) numberOfArguments = COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    childNodes = new Node*[numberOfArguments];
}

Node* OperatorNode::clone() const {
    Node* newNode = new OperatorNode(displayLabel);
    return cloneChildren(newNode);
}

double OperatorNode::evaluate(const Valuation &valuation) const {
    if (displayLabel == PLUS_OPERATOR_DISPLAY_LABEL)
        return childNodes[0]->evaluate(valuation) + childNodes[1]->evaluate(valuation);
    if (displayLabel == MINUS_OPERATOR_DISPLAY_LABEL)
        return childNodes[0]->evaluate(valuation) - childNodes[1]->evaluate(valuation);
    if (displayLabel == MULTIPLY_OPERATOR_DISPLAY_LABEL)
        return childNodes[0]->evaluate(valuation) * childNodes[1]->evaluate(valuation);
    if (displayLabel == DIVIDE_OPERATOR_DISPLAY_LABEL)
        return childNodes[0]->evaluate(valuation) / childNodes[1]->evaluate(valuation);
    if (displayLabel == SINUS_OPERATOR_DISPLAY_LABEL)
        return std::sin(childNodes[0]->evaluate(valuation) * M_PI / 180.0);
    if (displayLabel == COSINUS_OPERATOR_DISPLAY_LABEL)
        return std::cos(childNodes[0]->evaluate(valuation) * M_PI / 180.0);
    return 0;
}

void OperatorNode::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) {
    for (int i = 0; i < numberOfArguments; i++) {
        if (!userArgs.empty()) {
            std::string argString = userArgs.front();
            userArgs.pop_front();
            childNodes[i] = OperatorNode::allocateAndReturnPointer(argString);
            childNodes[i]->createChildren(userArgs, variableNames, warningNotifier);
        } else {
            warningNotifier.notifyEnterTooFewNodes();
            childNodes[i] = OperatorNode::allocateDefaultConstantNode();
        }
    }
}

void OperatorNode::addVariableNames(std::set<std::string> *variableNames) const {
    for (int i = 0; i < numberOfArguments; i++) {
        childNodes[i]->addVariableNames(variableNames);
    }
}

std::string OperatorNode::toString() const {
    return displayLabel;
}

std::string OperatorNode::toStringWithChildren() const {
    std::string stringToReturn = displayLabel;
    for (int i = 0; i < numberOfArguments; i++) {
        stringToReturn += " ";
        stringToReturn += childNodes[i]->toStringWithChildren();
    }
    return stringToReturn;
}

void OperatorNode::joinNode(Node *nodeToJoin) {
    Node *firstChild = childNodes[0];
    if (firstChild->hasChildren()) {
        firstChild->joinNode(nodeToJoin);
    } else {
        delete firstChild;
        childNodes[0] = nodeToJoin;
    }
}

Node* OperatorNode::allocateAndReturnPointer(std::string userInput) {
    if (userInput == PLUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(PLUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == MINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(MINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == MULTIPLY_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(MULTIPLY_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == DIVIDE_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(DIVIDE_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == SINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(SINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == COSINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(COSINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (Valuation::isConstant(userInput)) {
        double constantValue = std::stod(userInput);
        return new ConstantNode(constantValue);
    }
    
    removeInvalidCharacters(userInput);
    
    if (Valuation::isConstant(userInput)) {
        userInput = DEFAULT_VARIABLE_FIRST_LETTER + userInput;
    }
    
    return new VariableNode(userInput);
}

Node* OperatorNode::allocateDefaultConstantNode() {
    return new ConstantNode();
}

void OperatorNode::removeInvalidCharacters(std::string &userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c);
        }), userInput.end());
}

#endif
