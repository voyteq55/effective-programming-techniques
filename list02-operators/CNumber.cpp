#include "CNumber.h"
#include <iostream>
#include <sstream>

CNumber::CNumber() {
    vInitEmpty(NUMBER_DEFAULT_LENGTH);
}

CNumber::CNumber(int iLen) {
    vInitEmpty(iLen);
}

void CNumber::vInitEmpty(int iLen) {
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
    vMakeCopy(copy);
}

/* THIS IS WRONG */
//CNumber CNumber::operator=(const CNumber &pcNewValue) {
//    piNumber = pcNewValue.piNumber;
//    iLength = pcNewValue.iLength;
//    return *this;
//}

CNumber CNumber::operator=(const CNumber &pcNewValue) {
    delete[] piNumber;
    vMakeCopy(pcNewValue);
    return *this;
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
        vEnsureCapacity(iIndexCounter + 1);
        int iNewDigit = iValue % BASE;
        iValue = iValue / BASE;
        piNumber[iIndexCounter] = iNewDigit;
        iIndexCounter++;
    }
    vRemoveLeadingZeros();
    return *this;
}

CNumber CNumber::operator+(CNumber &pcNewValue) {
    if (bIsNegative && !pcNewValue.bIsNegative) {
        CNumber cToSubtract = this->cOpposite();
        return pcNewValue - cToSubtract;
    }
    if (!bIsNegative && pcNewValue.bIsNegative) {
        CNumber cToSubtract = pcNewValue.cOpposite();
        return *this - cToSubtract;
    }
    
    int iMaxLength = iLength > pcNewValue.iLength ? iLength : pcNewValue.iLength;
    CNumber cResult(iMaxLength + 1); // sum can have at most 1 digit more than the greater of added numbers
    int iRemainder = 0;
    for (int i = 0; i < iMaxLength; i++) {
        int iNewDigit = iRemainder;
        if (i < iLength) iNewDigit += piNumber[i];
        if (i < pcNewValue.iLength) iNewDigit += pcNewValue.piNumber[i];
        if (iNewDigit >= BASE) {
            iRemainder = 1;
            iNewDigit = iNewDigit % BASE;
        } else {
            iRemainder = 0;
        }
        cResult.piNumber[i] = iNewDigit;
    }
    
    if (iRemainder == 1) {
        cResult.piNumber[iMaxLength] = 1;
    }
    
    cResult.vRemoveLeadingZeros();
    if (bIsNegative && pcNewValue.bIsNegative) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

CNumber CNumber::operator+(int iNewValue) {
    CNumber cNewValue;
    cNewValue = iNewValue;
    return *this + cNewValue;
}

CNumber CNumber::operator-(CNumber &pcNewValue) {
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        return pcNewValue.cOpposite() + *this;
    }
    if (pcNewValue.bIsAbsoluteGreaterThan(*this)) {
        return (pcNewValue - *this).cOpposite();
    }
    
    CNumber cResult(iLength);
    int iNegativeRemainder = 0;
    for (int i = 0; i < iLength; i++) {
        int iFirstDigit = piNumber[i] - iNegativeRemainder;
        int iSecondDigit = i < pcNewValue.iLength ? pcNewValue.piNumber[i] : 0;
        
        if (iFirstDigit < iSecondDigit) {
            cResult.piNumber[i] = iFirstDigit + BASE - iSecondDigit;
            iNegativeRemainder = 1;
        } else {
            cResult.piNumber[i] = iFirstDigit - iSecondDigit;
            iNegativeRemainder = 0;
        }
    }
    
    cResult.vRemoveLeadingZeros();
    cResult.bIsNegative = bIsNegative;
    return cResult;
}

CNumber CNumber::operator-(int iNewValue) {
    CNumber cNewValue;
    cNewValue = iNewValue;
    return *this - cNewValue;
}

CNumber CNumber::operator*(CNumber &pcNewValue) {
    CNumber cResult(iLength + pcNewValue.iLength);
    
    for (int i = 0; i < pcNewValue.iLength; i++) {
        CNumber cSumPart(iLength + 1);
        int iRemainder = 0;
        for (int j = 0; j < iLength; j++) {
            int iResult = pcNewValue.piNumber[i] * piNumber[j] + iRemainder;
            cSumPart.piNumber[j] = iResult % BASE;
            iRemainder = iResult / BASE;
        }
        cSumPart.piNumber[iLength] = iRemainder;
        
        cSumPart.vRemoveLeadingZeros();
        cSumPart.vMultiplyBy10ToPowerOf(i);
        cResult = cResult + cSumPart;
    }
    
    cResult.vRemoveLeadingZeros();
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

CNumber CNumber::operator*(int iNewValue) {
    CNumber cNewValue;
    cNewValue = iNewValue;
    return *this * cNewValue;
}

CNumber CNumber::operator/(CNumber &pcNewValue) {
    if (pcNewValue.bIsZero()) return CNumber();
    
    CNumber cResult(iLength);
    CNumber cDividedNumber, cDividingNumber;
    cDividedNumber = 0;
    cDividingNumber = (pcNewValue.bIsNegative) ? pcNewValue.cOpposite() : pcNewValue;
    
    for (int i = iLength - 1; i >= 0; i--) {
        cDividedNumber.vMultiplyBy10ToPowerOf(1);
        cDividedNumber.piNumber[0] = piNumber[i];
        
        int iDivisionPart = 0;
        while (cDividingNumber.bIsAbsoluteSmallerThanOrEqual(cDividedNumber)) {
            cDividedNumber = cDividedNumber - cDividingNumber;
            iDivisionPart++;
        }
        cResult.piNumber[i] = iDivisionPart;
    }
    
    cResult.vRemoveLeadingZeros();
    if ((bIsNegative && !pcNewValue.bIsNegative) || (!bIsNegative && pcNewValue.bIsNegative)) {
        cResult.bIsNegative = true;
    }
    return cResult;
}

CNumber CNumber::operator/(int iNewValue) {
    CNumber cNewValue;
    cNewValue = iNewValue;
    return *this / cNewValue;
}

CNumber CNumber::operator<=(const CNumber &pcNewValue) {
    delete[] piNumber;
    vMakeCopy(pcNewValue);
    return *this;
}

CNumber operator<=(int &iValue, const CNumber &pcNewValue) {
    iValue = pcNewValue;
    return pcNewValue;
}

CNumber::operator int() const {
    int iResult = 0;
    int iPowerOf10 = 1;
    for (int i = 0; i < iLength; i++) {
        iResult += iPowerOf10 * piNumber[i];
        iPowerOf10 *= BASE;
    }
    return iResult;
}

CNumber CNumber::cOpposite() {
    CNumber cOpposite = *this;
    cOpposite.bIsNegative = !cOpposite.bIsNegative;
    return cOpposite;
}

// this function compares ABSOLUTE VALUES!
bool CNumber::bIsAbsoluteGreaterThan(CNumber &pcNewValue) {
    if (iLength > pcNewValue.iLength) return true;
    if (iLength < pcNewValue.iLength) return false;
    for (int i = iLength - 1; i >= 0; i--) {
        if (piNumber[i] > pcNewValue.piNumber[i]) return true;
        if (piNumber[i] < pcNewValue.piNumber[i]) return false;
    }
    return false;
}

// this function compares ABSOLUTE VALUES!
bool CNumber::bIsAbsoluteSmallerThanOrEqual(CNumber &pcNewValue) {
    return !(this->bIsAbsoluteGreaterThan(pcNewValue));
}

bool CNumber::bIsZero() {
    for (int i = iLength - 1; i >= 0; i--) {
        if (piNumber[i] != 0) return false;
    }
    return true;
}

void CNumber::vMultiplyBy10ToPowerOf(int iExponent) {
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

void CNumber::vMakeCopy(const CNumber &pcReference) {
    iLength = pcReference.iLength;
    piNumber = new int[iLength];
    for (int i = 0; i < iLength; i++) {
        piNumber[i] = pcReference.piNumber[i];
    }
    bIsNegative = pcReference.bIsNegative;
}

std::string CNumber::sToString() {
    std::ostringstream sStream;
    if (bIsNegative) {
        sStream << "-";
    }
    
    int iIndex = iLength - 1;
    while (iIndex > 0) {
        sStream << piNumber[iIndex];
        iIndex--;
    }
    sStream << piNumber[0];
    
    return sStream.str();
}

void CNumber::vRemoveLeadingZeros() {
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

void CNumber::vEnsureCapacity(int iRequiredLength) {
    if (iRequiredLength > iLength) {
        int iNewLength = iRequiredLength * 2;
        int *piNewNumber = new int[iNewLength];
        for (int i = 0; i < iLength; i++) {
            piNewNumber[i] = piNumber[i];
        }
        for (int i = iLength; i < iNewLength; i++) {
            piNewNumber[i] = 0;
        }
        delete[] piNumber;
        piNumber = piNewNumber;
        iLength = iNewLength;
    }
}
