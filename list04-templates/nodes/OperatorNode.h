#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"

const std::string DEFAULT_VARIABLE_FIRST_LETTER = "A";

const std::string PLUS_OPERATOR_DISPLAY_LABEL = "+";
const std::string MINUS_OPERATOR_DISPLAY_LABEL = "-";
const std::string MULTIPLY_OPERATOR_DISPLAY_LABEL = "*";
const std::string DIVIDE_OPERATOR_DISPLAY_LABEL = "/";
const std::string SINUS_OPERATOR_DISPLAY_LABEL = "sin";
const std::string COSINUS_OPERATOR_DISPLAY_LABEL = "cos";

const int PLUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int MULTIPLY_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int DIVIDE_OPERATOR_NUMBER_OF_ARGUMENTS = 2;
const int SINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;
const int COSINUS_OPERATOR_NUMBER_OF_ARGUMENTS = 1;

class OperatorNode: public Node {
public:
    OperatorNode();
    OperatorNode(std::string displayLabel);
    
    Node* clone() const override;
    
    double evaluate(const Valuation &valuation) const override;
    void createChildren(std::deque<std::string>& userArgs, std::set<std::string>* variableNames, WarningNotifier &warningNotifier) override;
    void addVariableNames(std::set<std::string>* variableNames) const override;
    std::string toString() const override;
    std::string toStringWithChildren() const override;
    void joinNode(Node *nodeToJoin) override;
    
    static Node* allocateAndReturnPointer(std::string userInput);
    static Node* allocateDefaultConstantNode();
    static void removeInvalidCharacters(std::string& userInput);
    
};

#endif
