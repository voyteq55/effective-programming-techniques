#include "CNumber.h"
#include <iostream>

CNumber::CNumber() {
    iLength = NUMBER_DEFAULT_LENGTH;
    piNumber = new int[iLength];
    for (int i = 0; i < iLength; i++) {
        piNumber[i] = 0;
    }
}

CNumber::~CNumber() {
    delete piNumber;
}

CNumber::CNumber(const CNumber &copy) {
    iLength = copy.iLength;
    piNumber = new int[iLength];
}

CNumber CNumber::operator=(int iValue) {
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

void CNumber::printTable() {
    std::cout << "[";
    if (iLength > 0) {
        std::cout << piNumber[iLength - 1];
    }
    for (int i = iLength - 2; i >= 0; i--) {
        std::cout << ", " << piNumber[i];
    }
    std::cout << "]\n";
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
