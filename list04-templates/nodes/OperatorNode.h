#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "OperatorFunctions.h"

const std::string DEFAULT_VARIABLE_FIRST_LETTER = "A";

const std::string PLUS_OPERATOR_DISPLAY_LABEL = "+";
const std::string MINUS_OPERATOR_DISPLAY_LABEL = "-";
const std::string MULTIPLY_OPERATOR_DISPLAY_LABEL = "*";
const std::string DIVIDE_OPERATOR_DISPLAY_LABEL = "/";
const std::string SINUS_OPERATOR_DISPLAY_LABEL = "sin";
const std::string COSINUS_OPERATOR_DISPLAY_LABEL = "cos";

const int PLUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int SINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;
const int COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;

template <typename T>
class OperatorNode: public Node<T> {
public:
    OperatorNode();
    OperatorNode(std::string displayLabel);
    
    Node<T>* clone() const override;
    
    T evaluate(const Valuation<T> &valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    void joinNode(Node<T> *nodeToJoin) override;
    
    static Node<T>* allocateAndReturnPointer(std::string userInput);
    static Node<T>* allocateDefaultConstantNode();
    static void removeInvalidCharacters(std::string& userInput);
    static Node<T>* getConstantValueNode(const std::string userInput);
    
};

template <typename T>
OperatorNode<T>::OperatorNode() {
    this->numberOfArguments = 0;
}

template <typename T>
OperatorNode<T>::OperatorNode(std::string label) {
    this->displayLabel = label;
    if (this->displayLabel == PLUS_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = PLUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (this->displayLabel == MINUS_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = MINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (this->displayLabel == MULTIPLY_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (this->displayLabel == DIVIDE_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (this->displayLabel == SINUS_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = SINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    if (this->displayLabel == COSINUS_OPERATOR_DISPLAY_LABEL) this->numberOfArguments = COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS;
    this->childNodes = new Node<T>*[this->numberOfArguments];
}

template <typename T>
Node<T>* OperatorNode<T>::clone() const {
    Node<T>* newNode = new OperatorNode<T>(this->displayLabel);
    return this->cloneChildren(newNode);
}

template <typename T>
T OperatorNode<T>::evaluate(const Valuation<T> &valuation) const {
    if (this->displayLabel == PLUS_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::plus(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
//        return this->childNodes[0]->evaluate(valuation) + this->childNodes[1]->evaluate(valuation);
    if (this->displayLabel == MINUS_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::minus(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
//        return this->childNodes[0]->evaluate(valuation) - this->childNodes[1]->evaluate(valuation);
    if (this->displayLabel == MULTIPLY_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::multiply(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
//        return this->childNodes[0]->evaluate(valuation) * this->childNodes[1]->evaluate(valuation);
    if (this->displayLabel == DIVIDE_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::divide(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
//        return this->childNodes[0]->evaluate(valuation) / this->childNodes[1]->evaluate(valuation);
    if (this->displayLabel == SINUS_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::sinus(this->childNodes[0]->evaluate(valuation));
//        return std::sin(this->childNodes[0]->evaluate(valuation) * M_PI / 180.0);
    if (this->displayLabel == COSINUS_OPERATOR_DISPLAY_LABEL)
        return OperatorFunctions<T>::cosinus(this->childNodes[0]->evaluate(valuation));
//        return std::cos(this->childNodes[0]->evaluate(valuation) * M_PI / 180.0);
    return T();
}

template <typename T>
void OperatorNode<T>::createChildren(std::deque<std::string> &userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) {
    for (int i = 0; i < this->numberOfArguments; i++) {
        if (!userArgs.empty()) {
            std::string argString = userArgs.front();
            userArgs.pop_front();
            this->childNodes[i] = OperatorNode<T>::allocateAndReturnPointer(argString);
            this->childNodes[i]->createChildren(userArgs, variableNames, warningNotifier);
        } else {
            warningNotifier.notifyEnterTooFewNodes();
            this->childNodes[i] = OperatorNode<T>::allocateDefaultConstantNode();
        }
    }
}

template <typename T>
void OperatorNode<T>::addVariableNames(std::set<std::string> *variableNames) const {
    for (int i = 0; i < this->numberOfArguments; i++) {
        this->childNodes[i]->addVariableNames(variableNames);
    }
}

template <typename T>
std::string OperatorNode<T>::toString() const {
    return this->displayLabel;
}

template <typename T>
std::string OperatorNode<T>::toStringWithChildren() const {
    std::string stringToReturn = this->displayLabel;
    for (int i = 0; i < this->numberOfArguments; i++) {
        stringToReturn += " ";
        stringToReturn += this->childNodes[i]->toStringWithChildren();
    }
    return stringToReturn;
}

template <typename T>
void OperatorNode<T>::joinNode(Node<T> *nodeToJoin) {
    Node<T> *firstChild = this->childNodes[0];
    if (firstChild->hasChildren()) {
        firstChild->joinNode(nodeToJoin);
    } else {
        delete firstChild;
        this->childNodes[0] = nodeToJoin;
    }
}

template <typename T>
Node<T>* OperatorNode<T>::allocateAndReturnPointer(std::string userInput) {
    if (userInput == PLUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(PLUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == MINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(MINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == MULTIPLY_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(MULTIPLY_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == DIVIDE_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(DIVIDE_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == SINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(SINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (userInput == COSINUS_OPERATOR_DISPLAY_LABEL) {
        return new OperatorNode(COSINUS_OPERATOR_DISPLAY_LABEL);
    }
    if (Valuation<T>::isConstant(userInput)) {
        return getConstantValueNode(userInput);
    }
    
    removeInvalidCharacters(userInput);
    
    if (Valuation<T>::isConstant(userInput)) {
        userInput = DEFAULT_VARIABLE_FIRST_LETTER + userInput;
    }
    
    return new VariableNode<T>(userInput);
}

template <typename T>
Node<T>* OperatorNode<T>::allocateDefaultConstantNode() {
    return new ConstantNode<T>();
}

template <typename T>
void OperatorNode<T>::removeInvalidCharacters(std::string &userInput) {}

template <>
inline void OperatorNode<int>::removeInvalidCharacters(std::string &userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c);
        }), userInput.end());
}

template <>
inline void OperatorNode<double>::removeInvalidCharacters(std::string &userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c) && c != '.';
        }), userInput.end());
}

template <typename T>
Node<T>* OperatorNode<T>::getConstantValueNode(const std::string userInput) {
    return new ConstantNode<T>();
}

template <>
inline Node<int>* OperatorNode<int>::getConstantValueNode(const std::string userInput) {
    return new ConstantNode<int>(std::stoi(userInput));
}

template <>
inline Node<double>* OperatorNode<double>::getConstantValueNode(const std::string userInput) {
    return new ConstantNode<double>(std::stod(userInput));
}

#endif
