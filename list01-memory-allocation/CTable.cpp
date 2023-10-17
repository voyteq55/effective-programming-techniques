#include <iostream>
#include "CTable.h"

CTable::CTable() {
    sName = DEFAULT_TABLE_NAME;
    pTable = new int[DEFAULT_TABLE_LENGTH];
    iTableLength = DEFAULT_TABLE_LENGTH;
    std::cout << DEFAULT_TEXT << sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    this->sName = sName;
    pTable = new int[iTableLen];
    iTableLength = iTableLen;
    std::cout << PARAM_TEXT << sName << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    sName = pcOther.sName + COPY;
    pTable = new int[pcOther.iTableLength];
    iTableLength = pcOther.iTableLength;

    for (int i = 0; i < iTableLength; i++) {
        pTable[i] = pcOther.pTable[i];
    }
    std::cout << COPY_TEXT << sName << std::endl;
}

CTable::~CTable() {
    delete[] pTable;
    std::cout << DELETE_TEXT << sName << std::endl;
}

bool CTable::bSetNewSize(int iNewTableLen) {
    if (iNewTableLen < 0) {
        return false;
    }

    int *pNewTable;
    pNewTable = new int[iNewTableLen];

    int realLength = (iNewTableLen < iTableLength) ? iNewTableLen : iTableLength;
    for (int i = 0; i < realLength; i++) {
        pNewTable[i] = pTable[i];
    }

    delete[] pTable;
    pTable = pNewTable;
    return true;
}

void vModTab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

void vModTab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}