#ifndef CNUMBER_H
#define CNUMBER_H
#include <string>

const int NUMBER_DEFAULT_LENGTH = 10;

class CNumber {
    private:
        int *piNumber;
        int iLength;

    public:
        CNumber();
        ~CNumber();
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
};

#endif
