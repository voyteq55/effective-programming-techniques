#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Tree.h"
#include "Valuation.h"
#include "WarningNotifier.h"
#include <iostream>
#include <sstream>

const std::string ENTER_COMMAND = "enter";
const std::string PRINT_COMMAND = "print";
const std::string COMP_COMMAND = "comp";
const std::string VARS_COMMAND = "vars";
const std::string JOIN_COMMAND = "join";
const std::string EXIT_COMMAND = "exit";
const std::string EMPTY_COMMAND = "<no command>";

const std::string COMMAND_START = "> ";
const std::string START_MESSAGE = "asdfasdfEnter a command ('enter <formula', 'vars', 'print', 'comp <var1> ... <varn>', 'join <formula>')";
const std::string INVALID_COMMAND_MESSAGE = "Invalid command name: ";
const std::string ENTER_TREE_MESSAGE = "Tree entered: ";
const std::string PRINT_TREE_MESSAGE = "Tree: ";
const std::string VARS_MESSAGE = "Variable names: ";
const std::string EVAL_MESSAGE = "Result: ";
const std::string EVAL_FAIL_MESSAGE = "Evaluation unsuccessful";
const std::string JOIN_TREE_MESSAGE = "Tree after joining: ";
const std::string EXIT_MESSAGE = "Program finished";

class ConsoleController {
public:
    ConsoleController();
    
    void start();
    
private:
    std::string executeCommand(std::string commandName, std::deque<std::string> userArgs, WarningNotifier &warningNotifier);
    std::deque<std::string> getInputDeque();
    
    bool isProgramRunning;
    Tree tree;
    Valuation valuation;
    
};

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

#endif
