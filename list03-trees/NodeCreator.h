#ifndef NODECREATOR_H
#define NODECREATOR_H

#include "Node.h"

class NodeCreator {
public:
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();
};

#endif
