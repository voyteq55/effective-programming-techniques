#include <iostream>
#include "CNumber.h"

int main() {
    std::cout << "helloooo" << "\n";
    CNumber n1;
    n1 = -103;
    std::cout << n1.toString();
    n1.printTable();
    CNumber n2(n1);
    std::cout << n2.toString();
    n2.printTable();
    n2 = 150212;
    std::cout << n1.toString();
    n1.printTable();
    std::cout << n2.toString();
    n2.printTable();
    
    CNumber cNum0, cNum1;
    cNum0 = 0;
    cNum1 = -501234;
    cNum0.printTable();
    cNum1.printTable();
    cNum0 = cNum1;
    cNum0.printTable();
    cNum1.printTable();
    
    return 0;
}
