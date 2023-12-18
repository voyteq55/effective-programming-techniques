#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "Node.h"
#include <string>

const int DEFAULT_CONSTANT_VALUE = 1;

template <typename T>
class ConstantNode: public Node<T> {
public:
    ConstantNode();
    ConstantNode(T value);
    
    Node<T>* clone() const override;
    
    T evaluate(const Valuation<T> &valuation) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const T constantValue;
    
};

template <typename T>
ConstantNode<T>::ConstantNode(): constantValue(DEFAULT_CONSTANT_VALUE) {}

template <>
inline ConstantNode<int>::ConstantNode(): constantValue(DEFAULT_CONSTANT_VALUE) {}

template <typename T>
ConstantNode<T>::ConstantNode(T value): constantValue(value) {}

template <typename T>
Node<T>* ConstantNode<T>::clone() const {
    return new ConstantNode<T>(constantValue);
}

template <typename T>
T ConstantNode<T>::evaluate(const Valuation<T> &valuation) const {
    return constantValue;
}

template <typename T>
std::string ConstantNode<T>::toString() const {
    return "no value";
}

template <>
inline std::string ConstantNode<int>::toString() const {
    return std::to_string(static_cast<int>(constantValue));
}

template <typename T>
std::string ConstantNode<T>::toStringWithChildren() const {
    return toString();
}

#endif
