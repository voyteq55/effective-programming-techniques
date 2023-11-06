#include "CNumber.h"
#include <iostream>

CNumber::CNumber() {
    iLength = NUMBER_DEFAULT_LENGTH;
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
    int iIndexCounter = 0;
    while (iValue >= 1) {
        ensureCapacity(iIndexCounter);
        int iNewDigit = iValue % 10;
        iValue = iValue / 10;
        piNumber[iIndexCounter] = iNewDigit;
        iIndexCounter++;
    }
    return *this;
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
