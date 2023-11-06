#include <iostream>
#include "CNumber.h"

int main() {
    std::cout << "helloooo" << "\n";
    CNumber n1;
    n1 = -1234567;
    n1.printTable();
    CNumber n2(n1);
    n2.printTable();
    n2 = 15;
    n1.printTable();
    n2.printTable();
    
    CNumber cNum0, cNum1;
    cNum0 = 368;
    cNum1 = -1567;
    cNum0.printTable();
    cNum1.printTable();
    cNum0 = cNum1;
    cNum0.printTable();
    cNum1.printTable();
    
    return 0;
}
