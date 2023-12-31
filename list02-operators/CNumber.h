#ifndef CNUMBER_H
#define CNUMBER_H
#include <string>

const int NUMBER_DEFAULT_LENGTH = 1;
const int BASE = 10;

class CNumber {
    private:
        int *piNumber;
        int iLength;
        bool bIsNegative;
        CNumber(int iLen);
        void vMakeCopy(const CNumber &reference);
        void vInitEmpty(int iLen);
        void vEnsureCapacity(int iRequiredLength);
        void vRemoveLeadingZeros();
        void vMultiplyBy10ToPowerOf(int iExponent);
        bool bIsAbsoluteGreaterThan(CNumber &pcNewValue); // this function compares ABSOLUTE VALUES!
        bool bIsAbsoluteSmallerThanOrEqual(CNumber &pcNewValue); // this function compares ABSOLUTE VALUES!
        bool bIsZero();
    
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
        CNumber operator<=(const CNumber &pcNewValue);
        friend CNumber operator<=(int &iValue, const CNumber &pcNewValue);
        CNumber cOpposite();
        std::string sToString();
};

#endif
