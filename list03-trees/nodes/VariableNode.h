#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "Node.h"
#include <string>

class VariableNode: public Node {
public:
    VariableNode();
    VariableNode(const std::string variableName);
    
    double evaluate(const Valuation &valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
private:
    const std::string variableName;
    
};

#endif
