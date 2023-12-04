#include <iostream>
#include <sstream>
#include "Tree.h"
#include "Node.h"
#include "VariableNode.h"
#include "NodeCreator.h"
#include "Valuation.h"

void tests() {
    Tree testTree;
    std::deque<std::string> myUserArgs;
    myUserArgs = {"+", "11", "+", "a", "1", "+"};
//    myUserArgs = {"+", "+", "+"};
    testTree.enterNewTree(myUserArgs);
    
    Valuation v;
    
    std::cout << testTree.toPrefixNotation() << "\n";
    std::cout << testTree.evaluate(v) << "\n";
    Node* n1 = NodeCreator::allocateAndReturnPointer("526");
    Node* n2 = NodeCreator::allocateAndReturnPointer("526a");
    Node* n3 = NodeCreator::allocateAndReturnPointer("+");
    Node* n4 = NodeCreator::allocateAndReturnPointer("x");
    Node* n5 = NodeCreator::allocateAndReturnPointer("y&$%@z");
}

int main() {
    tests();
    std::cout << "Enter a command ('enter <formula', 'vars', 'print', 'comp <var1> ... <varn>', 'join <formula>')\n";
    std::string res;
    Tree tree;
    Valuation valuation;
    
    bool isProgramRunning = true;
    while (isProgramRunning) {
        std::cout << "> ";
        std::string userInput;
        std::getline(std::cin, userInput);
        
        std::deque<std::string> wordsDeque;
        std::istringstream iss(userInput);
        std::string currentWord;
        
        while (iss >> currentWord) {
            wordsDeque.push_back(currentWord);
        }
        
        std::string firstWord = wordsDeque.front();
        wordsDeque.pop_front();
        if (firstWord == "enter") {
            tree.enterNewTree(wordsDeque);
        } else if (firstWord == "print") {
            std::cout << tree.toPrefixNotation() << "\n";
        } else if (firstWord == "comp") {
            std::cout << tree.evaluate(valuation) << "\n";
        } else if (firstWord == "vars") {
            std::cout << tree.getVariableNames() << "\n";
        } else if (firstWord == "exit") {
            isProgramRunning = false;
        }
    }
    
    return 0;
}
