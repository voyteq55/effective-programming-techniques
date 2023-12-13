#include "WarningNotifier.h"
#include <string>

#include <iostream>

WarningNotifier::WarningNotifier() {
    resetToDefault();
}

std::string WarningNotifier::getWarningMessage() {
    std::string warningMessage;
    if (missingNodesNumber != 0) warningMessage += "Entered too few arguments (" + std::to_string(missingNodesNumber) + " argument(s) autocompleted)\n";
    if (excessiveNodes != "") warningMessage += "Entered too many arguments (ignored: " + excessiveNodes + ")\n";
    if (expectedVariablesCount != actualVariablesCount) warningMessage += "Incorrect argument count: expected " + std::to_string(expectedVariablesCount) + ", got " + std::to_string(actualVariablesCount) + "\n";
    if (invalidArgument != "") warningMessage += "Invalid input (" + invalidArgument + +"), arguments have to be integers\n";
    return warningMessage;
}

void WarningNotifier::notifyEnterTooFewNodes() {
    missingNodesNumber++;
}

void WarningNotifier::notifyEnterTooManyNodes(std::deque<std::string> excessArguments) {
    while (!excessArguments.empty()) {
        excessiveNodes += excessArguments.front();
        excessiveNodes += " ";
        excessArguments.pop_front();
    }
}

void WarningNotifier::notifyCompIncorrectArgumentNumber(int expectedNumber, int actualNumber) {
    expectedVariablesCount = expectedNumber;
    actualVariablesCount = actualNumber;
}

void WarningNotifier::notifyCompInvalidArgument(std::string invalidArg) {
    invalidArgument = invalidArg;
}

void WarningNotifier::resetToDefault() {
    missingNodesNumber = 0;
    excessiveNodes = "";
    expectedVariablesCount = 0;
    actualVariablesCount = 0;
    invalidArgument = "";
}
