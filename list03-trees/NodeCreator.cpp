#include "NodeCreator.h"
#include "Node.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "PlusOperatorNode.h"
#include "OperatorConstants.h"
#include <string>

Node* NodeCreator::allocateAndReturnPointer(std::string userInput) {
    if (userInput == PLUS_OPERATOR_DISPLAY_LABEL) {
        return new PlusOperatorNode();
    }
    return new ConstantNode();
}

Node* NodeCreator::allocateDefaultConstantNode() {
    return new ConstantNode();
}
