#include <iostream>
#include "ex1.h"
#include "CTable.h"

int main() {
    vAllocTableFill34(10);
    int** pi2DimTable;
    bAllocTable2Dim(&pi2DimTable, 5, 3);
    bDeallocTable2Dim(pi2DimTable, 5, 3);
    
    CTable cStaticTable = CTable("statically allocated table", 10);
    cStaticTable.bSetNewSize(5);
    cStaticTable.bSetNewSize(15);

    cStaticTable.vSetName("statically allocated table with new name");

    CTable *pcDynamicTable = new CTable("dynamically allocated table", 20);
    (*pcDynamicTable).bSetNewSize(20);
    CTable *pcCopiedTable = (*pcDynamicTable).pcClone();

    delete pcDynamicTable;
    delete pcCopiedTable;

    return 0;
}