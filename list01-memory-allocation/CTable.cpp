#include <iostream>
#include "CTable.h"

void CTable::initTable(std::string sName, int iTableLen) {
    (*this).sName = sName;
    pTable = new int[iTableLen];
    iTableLength = iTableLen;
}

CTable::CTable() {
    initTable(DEFAULT_TABLE_NAME, DEFAULT_TABLE_LENGTH);
    std::cout << DEFAULT_TEXT << sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    initTable(sName, iTableLen);
    std::cout << PARAM_TEXT << sName << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    initTable(pcOther.sName + COPY, pcOther.iTableLength);
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
    iTableLength = iNewTableLen;

    std::cout << "try to change " << sName << " size to " << iNewTableLen << std::endl;

    return true;
}

void CTable::vPrintTabSize() {
    std::cout << "size of " << sName << ": " << iTableLength << std::endl;
}

void vModTab(CTable *pcTab, int iNewSize) {
    (*pcTab).bSetNewSize(iNewSize);
}

void vModTab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}