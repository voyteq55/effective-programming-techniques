#include <iostream>
#include "ex1.h"

void v_alloc_table_fill_34(int iSize) {
	int *pt_array;
	pt_array = new int[iSize];
	
	for (int i = 0; i < iSize; i++) {
		pt_array[i] = CONST_34;
	}

	std::cout << "[";
	for (int i = 0; i < iSize; i++) {
		if (i + 1 != iSize) {
			std::cout << pt_array[i] << ", ";
		} else {
			std::cout << pt_array[i] << "]" << std::endl;	
		}
	}

	delete[] pt_array;
}

int main() {
	v_alloc_table_fill_34(10);
}