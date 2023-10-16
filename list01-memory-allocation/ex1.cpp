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

bool b_alloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
    if (i_size_x <=0 || i_size_y <= 0) {
        return false;
    }
    
    *pi_table = new int*[i_size_x];
    for (int i = 0; i < i_size_x; i++) {
        *pi_table[i] = new int[i_size_y];
    }

    return true;
}

int main() {
    v_alloc_table_fill_34(10);
}