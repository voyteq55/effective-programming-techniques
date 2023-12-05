#ifndef NODECREATOR_H
#define NODECREATOR_H

#include "Node.h"

const std::string DEFAULT_VARIABLE_FIRST_LETTER = "A";

class NodeCreator {
public:
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();
    static bool isConstant(const std::string userInput);

private:
    static void removeInvalidCharacters(std::string& userInput);
    
};

#endif
