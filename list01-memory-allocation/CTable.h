#ifndef CTABLE_H
#define CTABLE_H

const int DEFAULT_TABLE_LENGTH = 16;
const std::string DEFAULT_TABLE_NAME = "Default table name";
const std::string DEFAULT_TEXT = "No param. constructor: ";
const std::string PARAM_TEXT = "Param. constructor: ";
const std::string COPY_TEXT = "Copying constructor: ";
const std::string DELETE_TEXT = "Deleting: ";
const std::string COPY = "_copy";

class CTable {
    private:
        std::string sName;
        int* pTable;
        int iTableLength;
        void initTable(std::string sName, int iTableLen);

    public:
        CTable();
        CTable(std::string sName, int iTableLen);
        CTable(const CTable &pcOther);
        ~CTable();
        void vSetName(std::string sName) { (*this).sName = sName; };
        bool bSetNewSize(int iTableLen);
        void vPrintTabSize();
        CTable *pcClone() { return new CTable(*this); };
};

void vModTab(CTable *pcTab, int iNewSize);
void vModTab(CTable pcTab, int iNewSize);

#endif
