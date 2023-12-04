#ifndef NODECREATOR_H
#define NODECREATOR_H

#include "Node.h"

class NodeCreator {
public:
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();
    static bool isConstant(const std::string userInput);

private:
    static void removeInvalidCharacters(std::string& userInput);
};

#endif
