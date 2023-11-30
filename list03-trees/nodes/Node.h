#ifndef NODE_H
#define NODE_H

#include <string>
#include <deque>
#include "Valuation.h"

class Node {
public:
    Node();
    
    virtual ~Node();
    
    virtual double evaluate(const Valuation& valuation) const = 0;
    virtual void createChildren(std::deque<std::string>& userArgs);
    virtual std::string toString() const;
    virtual std::string toStringWithChildren() const;
    
protected:
    std::string displayLabel;
};

#endif