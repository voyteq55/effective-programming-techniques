#ifndef VALUATION_H
#define VALUATION_H

#include "WarningNotifier.h"
#include <string>
#include <deque>
#include <set>

class Valuation {
public:
    Valuation();
    
    bool setValuation(std::deque<std::string> &userArgs, const std::set<std::string> *variableNames, WarningNotifier &warningNotifier);
    double evaluateVariable(std::string variableName) const;
    static bool isConstant(const std::string userInput);
    
private:
    std::unordered_map<std::string, double> variableValues;
    
};

#endif
