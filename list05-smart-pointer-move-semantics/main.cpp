#include <iostream>
#include "MySmartPointer.h"
#include "ConsoleController.h"

void testSmartPointers() {
    std::cout << "SMART POINTERS TEST" << "\n";
    MySmartPointer<std::string> aaa(new std::string("hello world"));
    
    MySmartPointer<std::string> bbb(new std::string("temporary string"));
    bbb = aaa;
    
    MySmartPointer<std::string> ccc(aaa);
    
    std::transform(bbb->begin(), bbb->end(), bbb->begin(), [](unsigned char c) {
        return std::toupper(c);
    });
}

void testMoveSemantics() {
    std::cout << "\nMOVE SEMANTICS TEST" << "\n";
    Tree<int> testTree1, testTree2, testTree3;
    std::deque<std::string> testArgs1 = {"+", "/", "abc", "2", "*", "a"};
    std::deque<std::string> testArgs2 = {"-", "sin", "x", "y"};
    std::deque<std::string> testArgs3 = {"newVar"};
    WarningNotifier w;
    testTree1.enterNewTree(testArgs1, w);
    testTree2.enterNewTree(testArgs2, w);
    testTree3.enterNewTree(testArgs3, w);
    
    std::cout << "testTree1: " << testTree1.toPrefixNotation() << ", vars: " << testTree1.getVariableNamesString() << "\n";
    std::cout << "testTree2: " << testTree2.toPrefixNotation() << ", vars: " << testTree2.getVariableNamesString() << "\n";
    std::cout << "testTree3: " << testTree3.toPrefixNotation() << ", vars: " << testTree3.getVariableNamesString() << "\n";
    
    Tree<int> testSumTree1;
    testSumTree1 = testTree1 + testTree2 + testTree3;
    
    std::cout << "\nAfter adding trees:\n";
    std::cout << "testSumTree1: " << testSumTree1.toPrefixNotation() << ", vars: " << testSumTree1.getVariableNamesString() << "\n";
    std::cout << "testTree1: " << testTree1.toPrefixNotation() << ", vars: " << testTree1.getVariableNamesString() << "\n";
    std::cout << "testTree2: " << testTree2.toPrefixNotation() << ", vars: " << testTree2.getVariableNamesString() << "\n";
    std::cout << "testTree3: " << testTree3.toPrefixNotation() << ", vars: " << testTree3.getVariableNamesString() << "\n";
}

int main() {
    testSmartPointers();
    testMoveSemantics();
    
    ConsoleController<int> consoleController;
    consoleController.start();
    
    return 0;
}
