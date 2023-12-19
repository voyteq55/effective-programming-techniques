#include "ConsoleController.h"

void assertEquals(std::string expected, std::string actual) {
    if (expected == actual) {
        std::cout << "TEST PASSED: expected - \"" << expected << "\", actual - \"" << actual << "\"\n";
    } else {
        std::cout << "!!!INCORRECT: expected - \"" << expected << "\", actual - \"" << actual << "\"\n";
    }
}

void tests() {
    std::cout << "PLUS:\n";
    assertEquals("abcdef", OperatorFunctions<std::string>::plus("abc", "def"));
    
    std::cout << "MINUS:\n";
    assertEquals("alaxalax", OperatorFunctions<std::string>::minus("alaxalaxala", "ala"));
    assertEquals("alaxalaxala", OperatorFunctions<std::string>::minus("alaxalaxala", "kot"));
    assertEquals("alaxalaa", OperatorFunctions<std::string>::minus("alaxalaxala", "xal"));
    assertEquals("alaxalaxala", OperatorFunctions<std::string>::minus("alaxalaxala", ""));
    assertEquals("", OperatorFunctions<std::string>::minus("", "alaxalaxala"));
    
    std::cout << "MULTIPLY:\n";
    assertEquals("alaxABCalaxABCala", OperatorFunctions<std::string>::multiply("alaxalaxala", "xABC"));
    assertEquals("alaxalaxala", OperatorFunctions<std::string>::multiply("alaxalaxala", "RDG"));
    assertEquals("alaxalaxala", OperatorFunctions<std::string>::multiply("alaxalaxala", ""));
    assertEquals("", OperatorFunctions<std::string>::multiply("", "alaxalaxala"));
    assertEquals("ABCABCABCaABCABCaaABCABC", OperatorFunctions<std::string>::multiply("AAAaAAaaAA", "ABC"));
    
    std::cout << "DIVIDE:\n";
    assertEquals("alaxalaxala", OperatorFunctions<std::string>::divide("alaxABCalaxABCala", "xABC"));
    assertEquals("alaxABCalaxABCal", OperatorFunctions<std::string>::divide("alaxABCalaxABCal", "ZZZ"));
    assertEquals("alaxABCalaxABCal", OperatorFunctions<std::string>::divide("alaxABCalaxABCal", ""));
    assertEquals("", OperatorFunctions<std::string>::divide("", "aaa"));
    assertEquals("adada", OperatorFunctions<std::string>::divide("abcdabcdabc", "abc"));
}

int main() {
    tests();
    ConsoleController<int> consoleController;
    consoleController.start();
    return 0;
}
