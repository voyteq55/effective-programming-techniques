#include "ConsoleController.h"
#include "Valuation.h"
#include <iostream>
#include <sstream>

ConsoleController::ConsoleController(): isProgramRunning(true) {}

void ConsoleController::start() {
    std::cout << START_MESSAGE << "\n";
    
    isProgramRunning = true;
    while (isProgramRunning) {
        std::cout << COMMAND_START;
        std::deque<std::string> inputDeque = getInputDeque();
        std::string firstWord = inputDeque.front();
        inputDeque.pop_front();
        std::string outputMessage = executeCommand(firstWord, inputDeque);
        std::cout << outputMessage << "\n";
    }
}

std::string ConsoleController::executeCommand(std::string commandName, std::deque<std::string> userArgs) {
    if (commandName == ENTER_COMMAND) {
        tree.enterNewTree(userArgs);
        return ENTER_TREE_MESSAGE + tree.toPrefixNotation();
    }
    if (commandName == PRINT_COMMAND) {
        return tree.toPrefixNotation();
    }
    if (commandName == COMP_COMMAND) {
        if (valuation.setValuation(userArgs, tree.getVariableNamesSet())) {
            return std::to_string(tree.evaluate(valuation));
        }
        return EVAL_FAIL_MESSAGE;
    }
    if (commandName == VARS_COMMAND) {
        return tree.getVariableNamesString();
    }
    if (commandName == JOIN_COMMAND) {
        tree.joinTree(userArgs);
        return JOIN_TREE_MESSAGE + tree.toPrefixNotation();
    }
    if (commandName == EXIT_COMMAND) {
        isProgramRunning = false;
        return EXIT_MESSAGE;
    }
    return INVALID_ARGUMENT_MESSAGE + commandName;
}

std::deque<std::string> ConsoleController::getInputDeque() {
    std::string userInput;
    std::getline(std::cin, userInput);
    
    std::deque<std::string> wordsDeque;
    std::istringstream iss(userInput);
    std::string currentWord;
    
    while (iss >> currentWord) {
        wordsDeque.push_back(currentWord);
    }
    return wordsDeque;
}
