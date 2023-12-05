#include <iostream>
#include <sstream>
#include "Tree.h"
#include "Node.h"
#include "VariableNode.h"
#include "NodeCreator.h"
#include "PlusOperatorNode.h"
#include "Valuation.h"
#include "ConsoleController.h"

void tests() {
    Tree testTree;
    WarningNotifier wn;
    std::deque<std::string> myUserArgs;
    myUserArgs = {"+", "11", "+", "a", "1", "+"};
//    myUserArgs = {"+", "+", "+"};
    testTree.enterNewTree(myUserArgs, wn);
    
    Valuation v;
    
    std::cout << testTree.toPrefixNotation() << "\n";
    std::cout << testTree.evaluate(v) << "\n";
    Node* n1 = NodeCreator::allocateAndReturnPointer("526");
    Node* n2 = NodeCreator::allocateAndReturnPointer("526a");
    Node* n3 = NodeCreator::allocateAndReturnPointer("+");
    Node* n4 = NodeCreator::allocateAndReturnPointer("x");
    Node* n5 = NodeCreator::allocateAndReturnPointer("y&$%@z");

    PlusOperatorNode p1;
    std::cout << "plus has children: " << p1.hasChildren() << "\n";
    std::cout << "526 has children: " << n1->hasChildren() << "\n";
    
    Tree testTree2;
    std::deque<std::string> args = {"*", "+", "a", "10", "/", "b", "*", "c", "3"};
    testTree2.enterNewTree(args, wn);
    std::cout << "drzewo: " << testTree2.toPrefixNotation() << "\n";
    std::cout << "vars: " << testTree2.getVariableNamesString() << "\n";
    Valuation v2;
    std::deque<std::string> valArgs = {"3", "14", "2"};
    v2.setValuation(valArgs, testTree2.getVariableNamesSet(), wn);
    std::cout << "wynik dla (3, 14, 2), powinien byc 30.(3): " << testTree2.evaluate(v2) << "\n";
    
    Tree joinedTree;
    std::deque<std::string> joinedTreeArgs = {"-", "+", "x", "77", "99"};
//    joinedTree.enterNewTree(joinedTreeArgs);
//    std::cout << "drzewo dodawane: " << joinedTree.toPrefixNotation() << "\n";
    
//    joinedTreeArgs = {"-", "sin", "x", "77"};
    testTree2.joinTree(joinedTreeArgs, wn);
    std::cout << "drzewo po dodaniu: " << testTree2.toPrefixNotation() << "\n";
    std::cout << "vars po dodaniu: " << testTree2.getVariableNamesString() << "\n";
    
    
    Tree testAdd1, testAdd2, testResult;
    std::deque<std::string> testAdd1Args = {"*", "var", "-", "5", "abc"};
    std::deque<std::string> testAdd2Args = {"+", "newVar"};
    testAdd1.enterNewTree(testAdd1Args, wn);
    testAdd2.enterNewTree(testAdd2Args, wn);
    std::cout << "drzewo 1 przed: " << testAdd1.toPrefixNotation() << ", args: " << testAdd1.getVariableNamesString() << "\n";
    std::cout << "drzewo 2 przed: " << testAdd2.toPrefixNotation() << ", args: " << testAdd2.getVariableNamesString()<< "\n";
    std::cout << "drzewo R przed: " << testResult.toPrefixNotation() << ", args: " << testResult.getVariableNamesString()<< "\n";
    
    std::deque<std::string> testResultArgs = {"/"};
    testResult.enterNewTree(testResultArgs, wn);
    testResult = testAdd1 + testAdd2;
    
    std::cout << "drzewo 1 po: " << testAdd1.toPrefixNotation() << ", args: " << testAdd1.getVariableNamesString() << "\n";
    std::cout << "drzewo 2 po: " << testAdd2.toPrefixNotation() << ", args: " << testAdd2.getVariableNamesString()<< "\n";
    std::cout << "drzewo 1 + drzewo 2 po: " << testResult.toPrefixNotation() << ", args: " << testResult.getVariableNamesString()<< "\n";
    
}

int main() {
    tests();
    ConsoleController consoleController;
    consoleController.start();
    
    return 0;
}
