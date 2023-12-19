#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "Node.h"
#include <string>

template <typename T>
class VariableNode: public Node<T> {
public:
    VariableNode();
    VariableNode(const std::string variableName);
    
    Node<T>* clone() const override;
    
    T evaluate(const Valuation<T>& valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier& warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const std::string variableName;
    
};

template <typename T>
VariableNode<T>::VariableNode(): variableName() {}

template <typename T>
VariableNode<T>::VariableNode(const std::string variableName): variableName(variableName) {}

template <typename T>
Node<T>* VariableNode<T>::clone() const {
    return new VariableNode<T>(variableName);
}

template <typename T>
T VariableNode<T>::evaluate(const Valuation<T>& valuation) const {
    return valuation.evaluateVariable(variableName);
}

template <typename T>
void VariableNode<T>::createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier& warningNotifier) {
    addVariableNames(variableNames);
}

template <typename T>
void VariableNode<T>::addVariableNames(std::set<std::string>* variableNames) const {
    variableNames->insert(variableName);
}

template <typename T>
std::string VariableNode<T>::toString() const {
    return variableName;
}

template <typename T>
std::string VariableNode<T>::toStringWithChildren() const {
    return toString();
}

#endif
