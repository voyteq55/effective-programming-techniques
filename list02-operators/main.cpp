#include <iostream>
#include "CNumber.h"

int main() {
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
    
    CNumber n3, n4, n5, n6, n7, zero;
    n3 = -1234567899;
    n4 = 1234567899;
    n5 = n3 + n4;
    n6 = n6 + n5;
    
    n6.printTable();
    n5.printTable();
    n5.multiplyBy10ToPowerOf(1);
    std::cout << n5.toString() << "\n";
    n5.printTable();
    
    n7 = n3 * n3 * n3;
//    n7 = n3 * zero
//    n7 = n3 * cNum0;
//    n7 = n3 * n4;
    std::cout << n7.toString() << "\n";
    n7.printTable();
    std::cout << n7.opposite().toString() << "\n";
    
    std::cout << (n4 - n2).toString() << "\n";
    std::cout << (n2 - n4).toString() << "\n";
    std::cout << (n4 - cNum1).toString() << "\n";
    std::cout << (cNum1 - n4).toString() << "\n";
    std::cout << (n4.opposite() - cNum1).toString() << "\n";
    std::cout << (cNum1 - n3).toString() << "\n";
    std::cout << (cNum1 - n3).toString() << "\n";
    
    std::cout << (cNum1 / n2).toString() << "\n";
    CNumber x1, x2, x3, x4, x5;
    x1 = -123;
    x2 = -2461;
    x3 = x2 / x1;
    std::cout << x2.toString() << " / " << x1.toString() << " = " << x3.toString() << "\n";
    x4 = x3 / x1;
    std::cout << x3.toString() << " / " << x1.toString() << " = " << x4.toString() << "\n";
    x5 = x1 / x3;
    std::cout << x1.toString() << " / " << x3.toString() << " = " << x5.toString() << "\n";
    x1 = x2 / x4;
    std::cout << x2.toString() << " / " << x4.toString() << " = " << x1.toString() << "\n";
    x4 = x2 / x5;
    std::cout << x2.toString() << " / " << x5.toString() << " = " << x4.toString() << "\n";
    
    return 0;
}
