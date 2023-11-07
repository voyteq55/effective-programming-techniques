#include <iostream>
#include "CNumber.h"

int main() {
    CNumber n1;
    n1 = -103;
    std::cout << n1.sToString();
    n1.printTable();
    CNumber n2(n1);
    std::cout << n2.sToString();
    n2.printTable();
    n2 = 150212;
    std::cout << n1.sToString();
    n1.printTable();
    std::cout << n2.sToString();
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
    std::cout << n5.sToString() << "\n";
    n5.printTable();
    
    n7 = n3 * n3 * n3;
//    n7 = n3 * zero
//    n7 = n3 * cNum0;
//    n7 = n3 * n4;
    std::cout << n7.sToString() << "\n";
    n7.printTable();
    std::cout << n7.cOpposite().sToString() << "\n";
    
    std::cout << (n4 - n2).sToString() << "\n";
    std::cout << (n2 - n4).sToString() << "\n";
    std::cout << (n4 - cNum1).sToString() << "\n";
    std::cout << (cNum1 - n4).sToString() << "\n";
    std::cout << (n4.cOpposite() - cNum1).sToString() << "\n";
    std::cout << (cNum1 - n3).sToString() << "\n";
    std::cout << (cNum1 - n3).sToString() << "\n";
    
    std::cout << (cNum1 / n2).sToString() << "\n";
    CNumber x1, x2, x3, x4, x5;
    x1 = -123;
    x2 = -2461;
    x3 = x2 / x1;
    std::cout << x2.sToString() << " / " << x1.sToString() << " = " << x3.sToString() << "\n";
    x4 = x3 / x1;
    std::cout << x3.sToString() << " / " << x1.sToString() << " = " << x4.sToString() << "\n";
    x5 = x1 / x3;
    std::cout << x1.sToString() << " / " << x3.sToString() << " = " << x5.sToString() << "\n";
    x1 = x2 / x4;
    std::cout << x2.sToString() << " / " << x4.sToString() << " = " << x1.sToString() << "\n";
    x4 = x2 / x5;
    std::cout << x2.sToString() << " / " << x5.sToString() << " = " << x4.sToString() << "\n";
    
    return 0;
}
