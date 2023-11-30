#ifndef VALUATION_H
#define VALUATION_H

#include <string>

class Valuation {
public:
    Valuation();
    
    double evaluateVariable(std::string variableName) const;
    
};

#endif
