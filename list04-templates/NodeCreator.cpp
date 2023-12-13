#include "NodeCreator.h"
#include "Node.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "PlusOperatorNode.h"
#include "MinusOperatorNode.h"
#include "MultiplyOperatorNode.h"
#include "DivideOperatorNode.h"
#include "SinusOperatorNode.h"
#include "CosinusOperatorNode.h"
#include <string>

Node* NodeCreator::allocateAndReturnPointer(std::string userInput) {
    if (userInput == PLUS_OPERATOR_DISPLAY_LABEL) {
        return new PlusOperatorNode();
    }
    if (userInput == MINUS_OPERATOR_DISPLAY_LABEL) {
        return new MinusOperatorNode();
    }
    if (userInput == MULTIPLY_OPERATOR_DISPLAY_LABEL) {
        return new MultiplyOperatorNode();
    }
    if (userInput == DIVIDE_OPERATOR_DISPLAY_LABEL) {
        return new DivideOperatorNode();
    }
    if (userInput == SINUS_OPERATOR_DISPLAY_LABEL) {
        return new SinusOperatorNode();
    }
    if (userInput == COSINUS_OPERATOR_DISPLAY_LABEL) {
        return new CosinusOperatorNode();
    }
    if (isConstant(userInput)) {
        double constantValue = std::stod(userInput);
        return new ConstantNode(constantValue);
    }
    
    removeInvalidCharacters(userInput);
    
    if (isConstant(userInput)) {
        userInput = DEFAULT_VARIABLE_FIRST_LETTER + userInput;
    }
    
    return new VariableNode(userInput);
}

bool NodeCreator::isConstant(const std::string userInput) {
    return std::all_of(userInput.begin(), userInput.end(), std::isdigit);
}

void NodeCreator::removeInvalidCharacters(std::string &userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c);
        }), userInput.end());
}

Node* NodeCreator::allocateDefaultConstantNode() {
    return new ConstantNode();
}
