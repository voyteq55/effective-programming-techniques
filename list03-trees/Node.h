#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    Node();
    
    virtual ~Node();
    
    virtual double evaluate() = 0;
    std::string toString();
    
private:
    std::string displayLabel;
};

#endif
