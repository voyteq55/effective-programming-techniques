#include <iostream>
#include "Tree.h"

int main() {
    Tree testTree;
    std::deque<std::string> myUserArgs;
    myUserArgs = {"+", "+", "+"};
    testTree.enterNewTree(myUserArgs);
    
    std::cout << testTree.toPrefixNotation() << "\n";
    return 0;
}
