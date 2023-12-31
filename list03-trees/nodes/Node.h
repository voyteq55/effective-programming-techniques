#ifndef NODE_H
#define NODE_H

#include <string>
#include <deque>
#include <set>
#include "Valuation.h"
#include "WarningNotifier.h"

class Node {
public:
    Node();
    Node(const Node &copy);
    
    Node& operator=(const Node &other);
    virtual Node* clone() const = 0;
    void makeCopy(const Node &other);
    
    virtual ~Node();
    
    virtual double evaluate(const Valuation& valuation) const = 0;
    virtual void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier);
    virtual void addVariableNames(std::set<std::string>* variableNames) const;
    virtual std::string toString() const;
    virtual std::string toStringWithChildren() const;
    virtual void joinNode(Node *nodeToJoin);
    bool hasChildren();
    void setChildNode(int index, Node *node);
    virtual Node* cloneChildren(Node *newNode) const;
    
protected:
    std::string displayLabel;
    int numberOfArguments;
    Node **childNodes;
    
    void deallocateMemory();
    
};

#endif
