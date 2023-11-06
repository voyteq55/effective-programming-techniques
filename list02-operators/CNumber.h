#ifndef CNUMBER_H
#define CNUMBER_H
#include <string>

const int NUMBER_DEFAULT_LENGTH = 1;

class CNumber {
    private:
        int *piNumber;
        int iLength;
        bool bIsNegative;
        void makeCopy(const CNumber &reference);
        CNumber(int iLen);
        void initEmpty(int iLen);
    
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
        CNumber opposite();
        bool operator>(CNumber &pcNewValue);
        std::string toString();
        void ensureCapacity(int iRequiredLength);
        void removeLeadingZeros();
        void multiplyBy10ToPowerOf(int iExponent);
        void printTable();
};

#endif
