#ifndef CTABLE_H
#define CTABLE_H

const int DEFAULT_TABLE_LENGTH = 16;
const std::string DEFAULT_TABLE_NAME = "Default table name";
const std::string DEFAULT_TEXT = "bezp: ";
const std::string PARAM_TEXT = "parametr: ";
const std::string COPY_TEXT = "kopiuj: ";
const std::string DELETE_TEXT = "usuwam: ";
const std::string COPY = "_copy";

class CTable {
    private:
        std::string sName;
        int* pTable;
        int iTableLength;

    public:
        CTable();
        CTable(std::string sName, int iTableLen);
        CTable(const CTable &pcOther);
        ~CTable();
        void vSetName(std::string sName) { this->sName = sName; };
        bool bSetNewSize(int iTableLen);
        void vPrintTabSize();
        CTable *pcClone() { return new CTable(*this); };
};

void vModTab(CTable *pcTab, int iNewSize);
void vModTab(CTable pcTab, int iNewSize);

#endif