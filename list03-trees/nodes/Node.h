#ifndef NODE_H
#define NODE_H

#include <string>
#include <deque>
#include <set>
#include "Valuation.h"

class Node {
public:
    Node();
    
    virtual ~Node();
    
    virtual double evaluate(const Valuation& valuation) const = 0;
    virtual void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames);
    virtual void addVariableNames(std::set<std::string>* variableNames) const;
    virtual std::string toString() const;
    virtual std::string toStringWithChildren() const;
    virtual void joinNode(Node *nodeToJoin);
    bool hasChildren();
    
protected:
    std::string displayLabel;
    int numberOfArguments;
    Node** childNodes;
    
};

#endif
