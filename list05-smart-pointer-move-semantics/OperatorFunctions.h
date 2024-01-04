#ifndef OPERATORFUNCTIONS_H
#define OPERATORFUNCTIONS_H

#include <cmath>

template <typename T>
class OperatorFunctions {
public:
    static T plus(const T& left, const T& right);
    static T minus(const T& left, const T& right);
    static T multiply(const T& left, const T& right);
    static T divide(const T& left, const T& right);
    static T sinus(const T& value);
    static T cosinus(const T& value);
};

template <typename T>
T OperatorFunctions<T>::plus(const T& left, const T& right) {
    return left;
}

template <>
int OperatorFunctions<int>::plus(const int& left, const int& right) {
    return left + right;
}

template <>
double OperatorFunctions<double>::plus(const double& left, const double& right) {
    return left + right;
}

template <>
std::string OperatorFunctions<std::string>::plus(const std::string& left, const std::string& right) {
    return left + right;
}

template <typename T>
T OperatorFunctions<T>::minus(const T& left, const T& right) {
    return left;
}

template <>
int OperatorFunctions<int>::minus(const int& left, const int& right) {
    return left - right;
}

template <>
double OperatorFunctions<double>::minus(const double& left, const double& right) {
    return left - right;
}

template <>
std::string OperatorFunctions<std::string>::minus(const std::string& left, const std::string& right) {
    std::string leftCopy = left;
    int positionOfLastOccurence = leftCopy.rfind(right);
    if (positionOfLastOccurence != std::string::npos) {
        return leftCopy.erase(positionOfLastOccurence, right.length());
    }
    return leftCopy;
}

template <typename T>
T OperatorFunctions<T>::multiply(const T& left, const T& right) {
    return left;
}

template <>
int OperatorFunctions<int>::multiply(const int& left, const int& right) {
    return left * right;
}

template <>
double OperatorFunctions<double>::multiply(const double& left, const double& right) {
    return left * right;
}

template <>
std::string OperatorFunctions<std::string>::multiply(const std::string& left, const std::string& right) {
    if (right.empty()) {
        return left;
    }
    std::string leftCopy = left;
    char firstCharOfRhs = right.at(0);
    std::string rhsRest = right.substr(1);
    int lhsCurrentIndex = 0;
    while (lhsCurrentIndex < leftCopy.size()) {
        if (leftCopy.at(lhsCurrentIndex) == firstCharOfRhs) {
            leftCopy.insert(lhsCurrentIndex + 1, rhsRest);
            lhsCurrentIndex += rhsRest.size();
        }
        lhsCurrentIndex ++;
    }
    return leftCopy;
}

template <typename T>
T OperatorFunctions<T>::divide(const T& left, const T& right) {
    return left;
}

template <>
int OperatorFunctions<int>::divide(const int& left, const int& right) {
    return left / right;
}

template <>
double OperatorFunctions<double>::divide(const double& left, const double& right) {
    return left / right;
}

template <>
std::string OperatorFunctions<std::string>::divide(const std::string& left, const std::string& right) {
    if (right.empty()) {
        return left;
    }
    std::string leftCopy = left;
    std::string firstCharOfRhs = right.substr(0, 1);
    int lhsCurrentIndex = leftCopy.find(right, 0);
    while (lhsCurrentIndex != std::string::npos) {
        leftCopy.replace(lhsCurrentIndex, right.size(), firstCharOfRhs);
        lhsCurrentIndex++;
        lhsCurrentIndex = leftCopy.find(right, lhsCurrentIndex);
    }
    return leftCopy;
}

template <typename T>
T OperatorFunctions<T>::sinus(const T& value) {
    return value;
}

template <>
int OperatorFunctions<int>::sinus(const int& value) {
    return std::sin(value * M_PI / 180.0);
}

template <>
double OperatorFunctions<double>::sinus(const double& value) {
    return std::sin(value * M_PI / 180.0);
}

template <typename T>
T OperatorFunctions<T>::cosinus(const T& value) {
    return value;
}

template <>
int OperatorFunctions<int>::cosinus(const int& value) {
    return std::cos(value * M_PI / 180.0);
}

template <>
double OperatorFunctions<double>::cosinus(const double& value) {
    return std::cos(value * M_PI / 180.0);
}

#endif
