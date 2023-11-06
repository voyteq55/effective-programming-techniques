#ifndef CNUMBER_H
#define CNUMBER_H
#include <string>

const int NUMBER_DEFAULT_LENGTH = 10;

class CNumber {
    private:
        int *piNumber;
        int iLength;
        bool bIsNegative;
        void makeCopy(const CNumber &reference);
    
    public:
        CNumber();
        ~CNumber();
        CNumber(const CNumber &copy);
        CNumber operator=(const CNumber &pcNewValue);
        CNumber operator+(CNumber &pcNewValue);
        CNumber operator*(CNumber &pcNewValue);
        CNumber operator-(CNumber &pcNewValue);
        CNumber operator/(CNumber &pcNewValue);
        CNumber operator=(int iValue);
        CNumber operator+(int iNewValue);
        CNumber operator*(int iNewValue);
        CNumber operator-(int iNewValue);
        CNumber operator/(int iNewValue);
        std::string toString();
        void ensureCapacity(int iRequiredLength);
        void printTable();
};

#endif
