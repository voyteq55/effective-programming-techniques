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

const std::unordered_map<std::string, int> OPERATOR_TO_NUMBER_OF_ARGUMENTS = {
    {PLUS_OPERATOR_DISPLAY_LABEL, PLUS_OPERATOR_NUMBER_OF_ARGUMENTS},
    {MINUS_OPERATOR_DISPLAY_LABEL, MINUS_OPERATOR_NUMBER_OF_ARGUMENTS},
    {MULTIPLY_OPERATOR_DISPLAY_LABEL, MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS},
    {DIVIDE_OPERATOR_DISPLAY_LABEL, DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS},
    {SINUS_OPERATOR_DISPLAY_LABEL, SINUS_OPERATOR_NUMBER_OF_ARGUMENTS},
    {COSINUS_OPERATOR_DISPLAY_LABEL, COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS}
};

template <typename T>
class OperatorNode: public Node<T> {
public:
    OperatorNode();
    OperatorNode(std::string displayLabel);
    
    Node<T>* clone() const override;
    
    T evaluate(const Valuation<T>& valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier& warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    void joinNode(Node<T>* nodeToJoin) override;
    
    static Node<T>* allocateAndReturnPointer(std::string userInput);
    static Node<T>* allocateDefaultConstantNode();
    static void removeInvalidCharacters(std::string& userInput);
    static Node<T>* getNewConstantValueNode(const std::string userInput);
    
};

template <typename T>
OperatorNode<T>::OperatorNode() {
    this->numberOfArguments = 0;
}

template <typename T>
OperatorNode<T>::OperatorNode(std::string label) {
    this->displayLabel = label;
    auto foundOperatorPosition = OPERATOR_TO_NUMBER_OF_ARGUMENTS.find(label);
    if (foundOperatorPosition != OPERATOR_TO_NUMBER_OF_ARGUMENTS.end()) {
        this->numberOfArguments = foundOperatorPosition->second;
    }
    this->childNodes = new Node<T>*[this->numberOfArguments];
}

template <typename T>
Node<T>* OperatorNode<T>::clone() const {
    Node<T>* newNode = new OperatorNode<T>(this->displayLabel);
    return this->cloneChildren(newNode);
}

template <typename T>
T OperatorNode<T>::evaluate(const Valuation<T>& valuation) const {
    if (this->displayLabel == PLUS_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::plus(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
    }
    if (this->displayLabel == MINUS_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::minus(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
    }
    if (this->displayLabel == MULTIPLY_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::multiply(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
    }
    if (this->displayLabel == DIVIDE_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::divide(this->childNodes[0]->evaluate(valuation), this->childNodes[1]->evaluate(valuation));
    }
    if (this->displayLabel == SINUS_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::sinus(this->childNodes[0]->evaluate(valuation));
    }
    if (this->displayLabel == COSINUS_OPERATOR_DISPLAY_LABEL) {
        return OperatorFunctions<T>::cosinus(this->childNodes[0]->evaluate(valuation));
    }
    return T();
}

template <typename T>
void OperatorNode<T>::createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier& warningNotifier) {
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
void OperatorNode<T>::addVariableNames(std::set<std::string>* variableNames) const {
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
void OperatorNode<T>::joinNode(Node<T>* nodeToJoin) {
    Node<T>* firstChild = this->childNodes[0];
    if (firstChild->hasChildren()) {
        firstChild->joinNode(nodeToJoin);
    } else {
        delete firstChild;
        this->childNodes[0] = nodeToJoin;
    }
}

template <typename T>
Node<T>* OperatorNode<T>::allocateAndReturnPointer(std::string userInput) {
    if (OPERATOR_TO_NUMBER_OF_ARGUMENTS.find(userInput) != OPERATOR_TO_NUMBER_OF_ARGUMENTS.end()) {
        return new OperatorNode(userInput);
    }
    if (Valuation<T>::isConstant(userInput)) {
        return getNewConstantValueNode(userInput);
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
void OperatorNode<T>::removeInvalidCharacters(std::string& userInput) {}

template <>
void OperatorNode<int>::removeInvalidCharacters(std::string& userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c);
        }), userInput.end());
}

template <>
void OperatorNode<double>::removeInvalidCharacters(std::string& userInput) {
    userInput.erase(
        std::remove_if(userInput.begin(), userInput.end(), [](char c) {
            return !std::isalnum(c) && c != COMMA;
        }), userInput.end());
}

template <typename T>
Node<T>* OperatorNode<T>::getNewConstantValueNode(const std::string userInput) {
    return new ConstantNode<T>();
}

template <>
Node<int>* OperatorNode<int>::getNewConstantValueNode(const std::string userInput) {
    return new ConstantNode<int>(std::stoi(userInput));
}

template <>
Node<double>* OperatorNode<double>::getNewConstantValueNode(const std::string userInput) {
    return new ConstantNode<double>(std::stod(userInput));
}

template <>
Node<std::string>* OperatorNode<std::string>::getNewConstantValueNode(const std::string userInput) {
    return new ConstantNode<std::string>(userInput.substr(1, userInput.size() - 2));
}

#endif
