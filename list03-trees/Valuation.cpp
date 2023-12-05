#include "Valuation.h"
#include "NodeCreator.h"
#include <string>
#include <set>

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
        if (!NodeCreator::isConstant(userArg)) {
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
