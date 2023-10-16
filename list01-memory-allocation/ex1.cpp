#include <iostream>
#include "ex1.h"

void vAllocTableFill34(int iSize) {
    int *pArray;
    pArray = new int[iSize];
    
    for (int i = 0; i < iSize; i++) {
        pArray[i] = CONST_34;
    }

    std::cout << "[";
    for (int i = 0; i < iSize; i++) {
        if (i + 1 != iSize) {
            std::cout << pArray[i] << ", ";
        } else {
            std::cout << pArray[i] << "]" << std::endl;	
        }
    }

    delete[] pArray;
}

bool bAllocTable2Dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX <=0 || iSizeY <= 0) {
        return false;
    }
    
    *piTable = new int*[iSizeX];
    for (int i = 0; i < iSizeX; i++) {
        *piTable[i] = new int[iSizeY];
    }

    return true;
}

int main() {
    vAllocTableFill34(10);
}