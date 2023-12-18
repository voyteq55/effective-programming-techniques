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

Valuation::Valuation() {}

bool Valuation::setValuation(std::deque<std::string> &userArgs, const std::set<std::string> *variableNames, WarningNotifier &warningNotifier) {
    variableValues.clear();
    if (userArgs.size() != variableNames->size()) {
        warningNotifier.notifyCompIncorrectArgumentNumber(variableNames->size(), userArgs.size());
        return false;
    }
    
    for (const std::string& variableName : *variableNames) {
        std::string userArg = userArgs.front();
        userArgs.pop_front();
        if (!isConstant(userArg)) {
            warningNotifier.notifyCompInvalidArgument(userArg);
            return false;
        }
        double variableValue = std::stod(userArg);
        variableValues.insert(std::make_pair(variableName, variableValue));
    }
    return true;
}

double Valuation::evaluateVariable(std::string variableName) const {
    if (variableValues.find(variableName) != variableValues.end()) {
        return variableValues.at(variableName);
    }
    return 0;
}

bool Valuation::isConstant(const std::string userInput) {
    return std::all_of(userInput.begin(), userInput.end(), std::isdigit);
}

#endif
