#include <iostream>
#include "tables.h"
#include "CTable.h"

int main() {
    vAllocTableFill34(10);
    int** pi2DimTable;
    bAllocTable2Dim(&pi2DimTable, 5, 3);
    bDeallocTable2Dim(pi2DimTable, 5, 3);
    
    CTable cStaticTable = CTable("statically allocated table", 10);
    cStaticTable.bSetNewSize(5);
    cStaticTable.vPrintTabSize();
    cStaticTable.bSetNewSize(15);
    cStaticTable.vPrintTabSize();

    cStaticTable.vSetName("statically allocated table with new name");

    CTable *pcDynamicTable = new CTable("dynamically allocated table", 20);
    (*pcDynamicTable).bSetNewSize(30);
    (*pcDynamicTable).vPrintTabSize();
    CTable *pcCopiedTable = (*pcDynamicTable).pcClone();
    (*pcCopiedTable).bSetNewSize(32);
    (*pcCopiedTable).vPrintTabSize();

    delete pcDynamicTable;
    delete pcCopiedTable;

    CTable *pcDefaultTable = new CTable();
    vModTab(pcDefaultTable, 100);
    (*pcDefaultTable).vPrintTabSize();

    vModTab(cStaticTable, 50);
    cStaticTable.vPrintTabSize();

    return 0;
}