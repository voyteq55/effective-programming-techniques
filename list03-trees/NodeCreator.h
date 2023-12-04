#ifndef NODECREATOR_H
#define NODECREATOR_H

#include "Node.h"

class NodeCreator {
public:
    static void extracted(std::string &userInput);
    
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();

private:
    static bool isConstant(const std::string userInput);
    static void removeInvalidCharacters(std::string& userInput);
};

#endif
