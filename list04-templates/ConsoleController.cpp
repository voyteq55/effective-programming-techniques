#include "ConsoleController.h"
#include "WarningNotifier.h"
#include "Valuation.h"
#include <iostream>
#include <sstream>

ConsoleController::ConsoleController(): isProgramRunning(true) {}

void ConsoleController::start() {
    std::cout << START_MESSAGE << "\n";
    
    WarningNotifier warningNotifier;
    isProgramRunning = true;
    while (isProgramRunning) {
        std::cout << COMMAND_START;
        std::string commandName;
        std::deque<std::string> inputDeque = getInputDeque();
        if (inputDeque.empty()) {
            commandName = EMPTY_COMMAND;
        } else {
            commandName = inputDeque.front();
            inputDeque.pop_front();
        }
        std::string outputMessage = executeCommand(commandName, inputDeque, warningNotifier);
        std::cout << warningNotifier.getWarningMessage();
        warningNotifier.resetToDefault();
        std::cout << outputMessage << "\n";
    }
}

std::string ConsoleController::executeCommand(std::string commandName, std::deque<std::string> userArgs, WarningNotifier &warningNotifier) {
    if (commandName == ENTER_COMMAND) {
        tree.enterNewTree(userArgs, warningNotifier);
        return ENTER_TREE_MESSAGE + tree.toPrefixNotation();
    }
    if (commandName == PRINT_COMMAND) {
        return PRINT_TREE_MESSAGE + tree.toPrefixNotation();
    }
    if (commandName == COMP_COMMAND) {
        if (valuation.setValuation(userArgs, tree.getVariableNamesSet(), warningNotifier)) {
            return EVAL_MESSAGE + std::to_string(tree.evaluate(valuation));
        }
        return EVAL_FAIL_MESSAGE;
    }
    if (commandName == VARS_COMMAND) {
        return VARS_MESSAGE + tree.getVariableNamesString();
    }
    if (commandName == JOIN_COMMAND) {
        tree.joinTree(userArgs, warningNotifier);
        return JOIN_TREE_MESSAGE + tree.toPrefixNotation();
    }
    if (commandName == EXIT_COMMAND) {
        isProgramRunning = false;
        return EXIT_MESSAGE;
    }
    return INVALID_COMMAND_MESSAGE + commandName;
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
