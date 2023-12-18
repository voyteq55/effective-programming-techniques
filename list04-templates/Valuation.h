#ifndef VALUATION_H
#define VALUATION_H

#include "WarningNotifier.h"
#include <string>
#include <deque>
#include <set>

template <typename T>
class Valuation {
public:
    Valuation();
    
    bool setValuation(std::deque<std::string> &userArgs, const std::set<std::string> *variableNames, WarningNotifier &warningNotifier);
    T evaluateVariable(std::string variableName) const;
    static bool isConstant(const std::string userInput);
    static T getConstantValue(const std::string userInput);
    
private:
    std::unordered_map<std::string, T> variableValues;
    
};

template <typename T>
Valuation<T>::Valuation() {}

template <typename T>
bool Valuation<T>::setValuation(std::deque<std::string> &userArgs, const std::set<std::string> *variableNames, WarningNotifier &warningNotifier) {
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
        T variableValue = getConstantValue(userArg);
        variableValues.insert(std::make_pair(variableName, variableValue));
    }
    return true;
}

template <typename T>
T Valuation<T>::evaluateVariable(std::string variableName) const {
    if (variableValues.find(variableName) != variableValues.end()) {
        return variableValues.at(variableName);
    }
    return T();
}

template <typename T>
bool Valuation<T>::isConstant(const std::string userInput) {
    return std::all_of(userInput.begin(), userInput.end(), std::isdigit);
}

template <>
inline bool Valuation<double>::isConstant(const std::string userInput) {
    return std::all_of(userInput.begin(), userInput.end(), [](char c) {
        return std::isdigit(c) || c == '.';
    });
}

template <typename T>
T Valuation<T>::getConstantValue(const std::string userInput) {
    return T();
}

template <>
inline int Valuation<int>::getConstantValue(const std::string userInput) {
    return std::stoi(userInput);
}

template <>
inline double Valuation<double>::getConstantValue(const std::string userInput) {
    return std::stod(userInput);
}

#endif
