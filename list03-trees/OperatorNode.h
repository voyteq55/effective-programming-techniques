#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"

class OperatorNode: public Node {
public:
    OperatorNode();
    
    virtual ~OperatorNode();
    
    void createChildren(std::deque<std::string>& userArgs) override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    
protected:
    double numberOfArguments;
    Node** childNodes;
    
};

#endif
