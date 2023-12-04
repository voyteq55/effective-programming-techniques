#ifndef VALUATION_H
#define VALUATION_H

#include <string>
#include <deque>
#include <set>

class Valuation {
public:
    Valuation();
    
    bool setValuation(std::deque<std::string> &userArgs, const std::set<std::string> *variableNames);
    double evaluateVariable(std::string variableName) const;
    
private:
    std::unordered_map<std::string, double> variableValues;
    
};

#endif
