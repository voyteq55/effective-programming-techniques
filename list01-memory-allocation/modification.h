#ifndef MOD_H
#define MOD_H

int **allocateTable2DBlock(int sizeX, int sizeY);
void deallocateTable2DBlock(int **pTable);
void printTable2DBlock(int **pTableBlock, int iSizeX, int iSizeY);

#endif