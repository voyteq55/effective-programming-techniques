#include <iostream>
#include "modification.h"

int **allocateTable2DBlock(int iSizeX, int iSizeY) {
    if (iSizeX < 0 || iSizeY < 0) {
        return NULL;
    }

    int **pTableBlock = new int*[iSizeX];
    *pTableBlock = new int[iSizeX * iSizeY];

    for (int i = 0; i < iSizeX; i++) {
        pTableBlock[i] = (*pTableBlock) + (i * iSizeY);
    }

    return pTableBlock;
}

void deallocateTable2DBlock(int **pTableBlock) {
    delete[] *pTableBlock;
    delete[] pTableBlock;
}

void printTable2DBlock(int **pTableBlock, int iSizeX, int iSizeY) {
    if (iSizeX < 0 || iSizeY < 0 || pTableBlock == NULL) {
        return;
    }
    for (int i = 0; i < iSizeX * iSizeY; i++) {
        std::cout << (*pTableBlock)[i] << " ";
    }
    std::cout << std::endl;
}