#ifndef VALUATION_H
#define VALUATION_H

#include "WarningNotifier.h"
#include <string>
#include <deque>
#include <set>

const std::string UNSUPPORTED_TYPE_REPRESENTATION = "<value type unsupported>";
const char DOUBLE_QUOTE = '"';
const char COMMA = '.';

template <typename T>
class Valuation {
public:
    Valuation();
    
    bool setValuation(std::deque<std::string>& userArgs, const std::set<std::string>* variableNames, WarningNotifier& warningNotifier);
    T evaluateVariable(std::string variableName) const;
    
    static bool isConstant(const std::string userInput);
    static T getConstantValue(const std::string userInput);
    static std::string toString(T value);
    
private:
    std::unordered_map<std::string, T> variableValues;
    
};

template <typename T>
Valuation<T>::Valuation() {}

template <typename T>
bool Valuation<T>::setValuation(std::deque<std::string>& userArgs, const std::set<std::string>* variableNames, WarningNotifier& warningNotifier) {
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
    return false;
}

template <>
bool Valuation<int>::isConstant(const std::string userInput) {
    return std::all_of(userInput.begin(), userInput.end(), std::isdigit);
}

template <>
bool Valuation<double>::isConstant(const std::string userInput) {
    if (userInput == std::string(1, COMMA)) {
        return false;
    }
    int numberOfCommas = 0;
    for (char c : userInput) {
        if (!std::isdigit(c)) {
            if (c != COMMA || numberOfCommas > 0) {
                return false;
            }
            numberOfCommas++;
        }
    }
    return true;
}

template <>
bool Valuation<std::string>::isConstant(const std::string userInput) {
    return userInput.size() >= 2 && userInput.front() == DOUBLE_QUOTE && userInput.back() == DOUBLE_QUOTE;
}

template <typename T>
T Valuation<T>::getConstantValue(const std::string userInput) {
    return T();
}

template <>
int Valuation<int>::getConstantValue(const std::string userInput) {
    return std::stoi(userInput);
}

template <>
double Valuation<double>::getConstantValue(const std::string userInput) {
    return std::stod(userInput);
}

template <>
std::string Valuation<std::string>::getConstantValue(const std::string userInput) {
    return userInput.substr(1, userInput.size() - 2);
}

template <typename T>
std::string Valuation<T>::toString(T value) {
    return UNSUPPORTED_TYPE_REPRESENTATION;
}

template <>
std::string Valuation<int>::toString(int value) {
    return std::to_string(value);
}

template <>
std::string Valuation<double>::toString(double value) {
    return std::to_string(value);
}

template <>
std::string Valuation<std::string>::toString(std::string value) {
    return value;
}

#endif
