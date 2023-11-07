#include "CNumber.h"
#include <iostream>
#include <sstream>

CNumber::CNumber() {
    initEmpty(NUMBER_DEFAULT_LENGTH);
}

CNumber::CNumber(int iLen) {
    initEmpty(iLen);
}

void CNumber::initEmpty(int iLen) {
    iLength = iLen;
    piNumber = new int[iLength];
    for (int i = 0; i < iLength; i++) {
        piNumber[i] = 0;
    }
    bIsNegative = false;
}

CNumber::~CNumber() {
    delete[] piNumber;
}

CNumber::CNumber(const CNumber &copy) {
    makeCopy(copy);
}

CNumber CNumber::operator=(int iValue) {
    bIsNegative = iValue < 0 ? true : false;
    if (bIsNegative) {
        iValue = -iValue;
    }
    for (int i = 0; i < iLength; i++) {
        piNumber[i] = 0;
    }
    int iIndexCounter = 0;
    while (iValue >= 1) {
        ensureCapacity(iIndexCounter + 1);
        int iNewDigit = iValue % 10;
        iValue = iValue / 10;
        piNumber[iIndexCounter] = iNewDigit;
        iIndexCounter++;
    }
    removeLeadingZeros();
    return *this;
}

CNumber CNumber::operator+(CNumber &pcNewValue) {
    if (bIsNegative && !pcNewValue.bIsNegative) {
        return pcNewValue.opposite() - *this;
    }
    if (!bIsNegative && pcNewValue.bIsNegative) {
        return (*this).opposite() - pcNewValue;
    }
    
    int iMaxLength = iLength > pcNewValue.iLength ? iLength : pcNewValue.iLength;
    CNumber cResult(iMaxLength + 1); // sum can have at most 1 digit more than the greater of added numbers
    int iRemainder = 0;
    for (int i = 0; i < iMaxLength; i++) {
        int iNewDigit = iRemainder;
        if (i < iLength) iNewDigit += piNumber[i];
        if (i < pcNewValue.iLength) iNewDigit += pcNewValue.piNumber[i];
        if (iNewDigit >= 10) {
            iRemainder = 1;
            iNewDigit = iNewDigit % 10;
        } else {
            iRemainder = 0;
        }
        cResult.piNumber[i] = iNewDigit;
    }
    
    if (iRemainder == 1) {
        cResult.piNumber[iMaxLength] = 1;
    }
    
    cResult.removeLeadingZeros();
    if (bIsNegative && pcNewValue.bIsNegative) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

CNumber CNumber::operator-(CNumber &pcNewValue) {
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        return pcNewValue.opposite() + *this;
    }
    if (pcNewValue > *this) {
        return (pcNewValue - *this).opposite();
    }
    
    CNumber cResult(iLength);
    int iNegativeRemainder = 0;
    for (int i = 0; i < iLength; i++) {
        int iFirstDigit = piNumber[i] - iNegativeRemainder;
        int iSecondDigit = i < pcNewValue.iLength ? pcNewValue.piNumber[i] : 0;
        
        if (iFirstDigit < iSecondDigit) {
            cResult.piNumber[i] = iFirstDigit + 10 - iSecondDigit;
            iNegativeRemainder = 1;
        } else {
            cResult.piNumber[i] = iFirstDigit - iSecondDigit;
            iNegativeRemainder = 0;
        }
    }
    
    cResult.removeLeadingZeros();
    cResult.bIsNegative = bIsNegative;
    return cResult;
}

CNumber CNumber::operator*(CNumber &pcNewValue) {
    CNumber cResult(iLength + pcNewValue.iLength);
    
    for (int i = 0; i < pcNewValue.iLength; i++) {
        CNumber cSumPart(iLength + 1);
        int iRemainder = 0;
        for (int j = 0; j < iLength; j++) {
            int iResult = pcNewValue.piNumber[i] * piNumber[j] + iRemainder;
            cSumPart.piNumber[j] = iResult % 10;
            iRemainder = iResult / 10;
        }
        cSumPart.piNumber[iLength] = iRemainder;
        
        cSumPart.removeLeadingZeros();
        cSumPart.multiplyBy10ToPowerOf(i);
        cResult = cResult + cSumPart;
    }
    
    cResult.removeLeadingZeros();
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

// TODO check if pcNewValue is zero
CNumber CNumber::operator/(CNumber &pcNewValue) {
    if (pcNewValue.isZero()) return CNumber();
    
    CNumber cResult(iLength);
    CNumber cDividedNumber, cDividingNumber;
    cDividedNumber = 0;
    cDividingNumber = (pcNewValue.bIsNegative) ? pcNewValue.opposite() : pcNewValue;
    
    for (int i = iLength - 1; i >= 0; i--) {
        cDividedNumber.multiplyBy10ToPowerOf(1);
        cDividedNumber.piNumber[0] = piNumber[i];
        
        int iDivisionPart = 0;
        while (cDividingNumber <= cDividedNumber) {
            cDividedNumber = cDividedNumber - cDividingNumber;
            iDivisionPart++;
        }
        cResult.piNumber[i] = iDivisionPart;
    }
    
    cResult.removeLeadingZeros();
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

CNumber CNumber::opposite() {
    CNumber cOpposite = *this;
    cOpposite.bIsNegative = !cOpposite.bIsNegative;
    return cOpposite;
}

bool CNumber::operator>(CNumber &pcNewValue) {
    if (iLength > pcNewValue.iLength) return true;
    if (iLength < pcNewValue.iLength) return false;
    for (int i = iLength - 1; i >= 0; i--) {
        if (piNumber[i] > pcNewValue.piNumber[i]) return true;
        if (piNumber[i] < pcNewValue.piNumber[i]) return false;
    }
    return false;
}

bool CNumber::operator<=(CNumber &pcNewValue) {
    return !operator>(pcNewValue);
}

bool CNumber::isZero() {
    for (int i = iLength - 1; i >= 0; i--) {
        if (piNumber[i] != 0) return false;
    }
    return true;
}

void CNumber::multiplyBy10ToPowerOf(int iExponent) {
    if ((iExponent > 0) && (piNumber[iLength - 1] != 0)) {
        int iNewLength = iLength + iExponent;
        int *piNewNumber = new int[iNewLength];
        
        for (int i = 0; i < iLength; i++) {
            piNewNumber[i + iExponent] = piNumber[i];
        }
        for (int i = 0; i < iExponent; i++) {
            piNewNumber[i] = 0;
        }
        
        iLength = iNewLength;
        delete[] piNumber;
        piNumber = piNewNumber;
    }
}

/* THIS IS WRONG */
//CNumber CNumber::operator=(const CNumber &pcNewValue) {
//    piNumber = pcNewValue.piNumber;
//    iLength = pcNewValue.iLength;
//    return *this;
//}

CNumber CNumber::operator=(const CNumber &pcNewValue) {
    delete[] piNumber;
    makeCopy(pcNewValue);
    return *this;
}

void CNumber::makeCopy(const CNumber &reference) {
    iLength = reference.iLength;
    piNumber = new int[iLength];
    for (int i = 0; i < iLength; i++) {
        piNumber[i] = reference.piNumber[i];
    }
    bIsNegative = reference.bIsNegative;
}

std::string CNumber::toString() {
    std::ostringstream stream;
    if (bIsNegative) {
        stream << "-";
    }
    
    int index = iLength - 1;
    while (index > 0) {
        stream << piNumber[index];
        index--;
    }
    stream << piNumber[0];
    
    return stream.str();
}

void CNumber::removeLeadingZeros() {
    if (piNumber[iLength - 1] == 0) {
        int iNewLength = iLength;
        while (piNumber[iNewLength - 1] == 0 && iNewLength > 1) {
            iNewLength--;
        }
        iLength = iNewLength;
        int *piNewNumber = new int[iNewLength];
        for (int i = 0; i < iNewLength; i++) {
            piNewNumber[i] = piNumber[i];
        }
        delete[] piNumber;
        piNumber = piNewNumber;
    }
}

void CNumber::printTable() {
    std::cout << "[";
    if (iLength > 0) {
        std::cout << piNumber[iLength - 1];
    }
    for (int i = iLength - 2; i >= 0; i--) {
        std::cout << ", " << piNumber[i];
    }
    std::cout << "]";
    if (bIsNegative) {
        std::cout << " (negative)";
    }
    std::cout << "\n";
}

void CNumber::ensureCapacity(int iRequiredLength) {
    if (iRequiredLength > iLength) {
        int iNewLength = iRequiredLength * 2;
        int *piNewNumber = new int[iNewLength];
        for (int i = 0; i < iLength; i++) {
            piNewNumber[i] = piNumber[i];
        }
        for (int i = iLength; i < iNewLength; i++) {
            piNewNumber[i] = 0;
        }
        delete piNumber;
        piNumber = piNewNumber;
        iLength = iNewLength;
    }
}
