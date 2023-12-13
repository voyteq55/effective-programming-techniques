#ifndef WARNINGNOTIFIER_H
#define WARNINGNOTIFIER_H

#include <string>
#include <deque>

class WarningNotifier {
public:
    WarningNotifier();
    
    std::string getWarningMessage();
    void notifyEnterTooFewNodes();
    void notifyEnterTooManyNodes(std::deque<std::string> excessArguments);
    void notifyCompIncorrectArgumentNumber(int expectedNumber, int actualNumber);
    void notifyCompInvalidArgument(std::string invalidArg);
    void resetToDefault();
    
private:
    int missingNodesNumber;
    std::string excessiveNodes;
    int expectedVariablesCount;
    int actualVariablesCount;
    std::string invalidArgument;
};

#endif
