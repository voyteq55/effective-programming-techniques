#ifndef OPERATORFUNCTIONS_H
#define OPERATORFUNCTIONS_H

#include <cmath>

template <typename T>
class OperatorFunctions {
public:
    static T plus(T left, T right);
    static T minus(T left, T right);
    static T multiply(T left, T right);
    static T divide(T left, T right);
    static T sinus(T value);
    static T cosinus(T value);
};

template <typename T>
T OperatorFunctions<T>::plus(T left, T right) {
    return left;
}

template <>
int OperatorFunctions<int>::plus(int left, int right) {
    return left + right;
}

template <>
double OperatorFunctions<double>::plus(double left, double right) {
    return left + right;
}

template <>
std::string OperatorFunctions<std::string>::plus(std::string left, std::string right) {
    return left + right;
}

template <typename T>
T OperatorFunctions<T>::minus(T left, T right) {
    return left;
}

template <>
int OperatorFunctions<int>::minus(int left, int right) {
    return left - right;
}

template <>
double OperatorFunctions<double>::minus(double left, double right) {
    return left - right;
}

template <typename T>
T OperatorFunctions<T>::multiply(T left, T right) {
    return left;
}

template <>
int OperatorFunctions<int>::multiply(int left, int right) {
    return left * right;
}

template <>
double OperatorFunctions<double>::multiply(double left, double right) {
    return left * right;
}

template <typename T>
T OperatorFunctions<T>::divide(T left, T right) {
    return left;
}

template <>
int OperatorFunctions<int>::divide(int left, int right) {
    return left / right;
}

template <>
double OperatorFunctions<double>::divide(double left, double right) {
    return left / right;
}

template <typename T>
T OperatorFunctions<T>::sinus(T value) {
    return value;
}

template <>
int OperatorFunctions<int>::sinus(int value) {
    return std::sin(value * M_PI / 180.0);
}

template <>
double OperatorFunctions<double>::sinus(double value) {
    return std::sin(value * M_PI / 180.0);
}

template <typename T>
T OperatorFunctions<T>::cosinus(T value) {
    return value;
}

template <>
int OperatorFunctions<int>::cosinus(int value) {
    return std::cos(value * M_PI / 180.0);
}

template <>
double OperatorFunctions<double>::cosinus(double value) {
    return std::cos(value * M_PI / 180.0);
}

#endif
