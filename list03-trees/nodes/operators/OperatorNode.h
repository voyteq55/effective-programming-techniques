#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"

class OperatorNode: public Node {
public:
    OperatorNode();
    
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    void joinNode(Node *nodeToJoin) override;
    
};

#endif
