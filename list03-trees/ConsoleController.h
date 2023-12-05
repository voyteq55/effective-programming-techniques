#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Tree.h"
#include "Valuation.h"

const std::string ENTER_COMMAND = "enter";
const std::string PRINT_COMMAND = "print";
const std::string COMP_COMMAND = "comp";
const std::string VARS_COMMAND = "vars";
const std::string JOIN_COMMAND = "join";
const std::string EXIT_COMMAND = "exit";

const std::string COMMAND_START = "> ";
const std::string START_MESSAGE = "Enter a command ('enter <formula', 'vars', 'print', 'comp <var1> ... <varn>', 'join <formula>')";
const std::string INVALID_COMMAND_MESSAGE = "Invalid command name: ";
const std::string ENTER_TREE_MESSAGE = "Tree entered: ";
const std::string EVAL_FAIL_MESSAGE = "Evaluation unsuccessful";
const std::string JOIN_TREE_MESSAGE = "Tree after joining: ";
const std::string EXIT_MESSAGE = "Program finished";

class ConsoleController {
public:
    ConsoleController();
    
    void start();
    
private:
    std::string executeCommand(std::string commandName, std::deque<std::string> userArgs);
    std::deque<std::string> getInputDeque();
    
    bool isProgramRunning;
    Tree tree;
    Valuation valuation;
    
};

#endif
