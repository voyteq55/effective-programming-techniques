#include <iostream>
#include "CNumber.h"
#include "testCNumber.h"

void vTestExercise2Code() {
    CNumber cNum0, cNum1;
    cNum0 = 368;
    cNum1 = 1567;
    cNum0 = cNum1;
}

void vTestAddition() {
    std::cout << "\nADDITION TESTS:\n";
    CNumber n1, n2, n3, n4, n5, n6;
    n1 = 1234567890;
    n2 = n1 + n1 + 7;
    std::cout << n1.sToString() << " + " << n1.sToString() << " + 7 = " << n2.sToString() << "\n";
    n3 = -67899;
    n4 = 123456;
    std::cout << n3.sToString() << " + " << n4.sToString() << " = " << (n3 + n4).sToString() << "\n";
    std::cout << n4.sToString() << " + " << n3.sToString() << " = " << (n4 + n3).sToString() << "\n";
    std::cout << n3.sToString() << " + " << n3.sToString() << " = " << (n3 + n3).sToString() << "\n";
    n5 = -987654;
    std::cout << n5.sToString() << " + " << n4.sToString() << " = " << (n5 + n4).sToString() << "\n";
    std::cout << n4.sToString() << " + " << n5.sToString() << " = " << (n4 + n5).sToString() << "\n";
    n6 = 67899;
    std::cout << n3.sToString() << " + " << n6.sToString() << " = " << (n3 + n6).sToString() << "\n";
    std::cout << n3.sToString() << " + 15 + " << n6.sToString() << " = " << (n3 + 15 + n6).sToString() << "\n";
}

void vTestSubtraction() {
    std::cout << "\nSUBTRACTION TESTS:\n";
    CNumber n1, n2, n3, n4, n5, n6;
    n1 = 1234567890;
    n2 = n1 - n1;
    std::cout << n1.sToString() << " - " << n1.sToString() << " = " << n2.sToString() << "\n";
    n3 = -67899;
    n4 = 123456;
    std::cout << n3.sToString() << " - " << n4.sToString() << " = " << (n3 - n4).sToString() << "\n";
    std::cout << n4.sToString() << " - " << n3.sToString() << " = " << (n4 - n3).sToString() << "\n";
    n5 = -987654;
    std::cout << n5.sToString() << " - " << n4.sToString() << " = " << (n5 - n4).sToString() << "\n";
    std::cout << n4.sToString() << " - " << n5.sToString() << " = " << (n4 - n5).sToString() << "\n";
    std::cout << n1.sToString() << " - " << n4.sToString() << " = " << (n1 - n4).sToString() << "\n";
    n6 = 67899;
    std::cout << n3.sToString() << " - " << n5.sToString() << " = " << (n3 - n5).sToString() << "\n";
    std::cout << n5.sToString() << " - " << n3.sToString() << " = " << (n5 - n3).sToString() << "\n";
    std::cout << n3.sToString() << " - 15 - " << n6.sToString() << " = " << (n3 - 15 - n6).sToString() << "\n";
}

void vTestMultiplication() {
    std::cout << "\nMULTIPLICATION TESTS:\n";
    CNumber n1, n2, n3, n4, n5;
    n1 = 11111111;
    n2 = n1 * n1;
    std::cout << n1.sToString() << " * " << n1.sToString() << " = " << n2.sToString() << "\n";
    n3 = -67899;
    n4 = 123456;
    std::cout << n3.sToString() << " * " << n4.sToString() << " = " << (n3 * n4).sToString() << "\n";
    std::cout << n4.sToString() << " * " << n3.sToString() << " = " << (n4 * n3).sToString() << "\n";
    n5 = -987654;
    std::cout << n5.sToString() << " * " << n4.sToString() << " = " << (n5 * n4).sToString() << "\n";
    std::cout << n4.sToString() << " * " << n5.sToString() << " = " << (n4 * n5).sToString() << "\n";
    std::cout << n1.sToString() << " * " << n4.sToString() << " = " << (n1 * n4).sToString() << "\n";
    std::cout << n3.sToString() << " * " << n3.sToString() << " = " << (n3 * n3).sToString() << "\n";
    std::cout << n4.sToString() << " * 0 = " << (n4 * 0).sToString() << "\n";
}

void vTestDivision() {
    std::cout << "\nDIVISION TESTS:\n";
    CNumber n1, n2, n3, n4, n5, n6, n7;
    n1 = 432426;
    std::cout << n1.sToString() << " / " << n1.sToString() << " = " << (n1 / n1).sToString() << "\n";
    std::cout << "(" << n1.sToString() << " - 1) / " << n1.sToString() << " = " << ((n1 - 1) / n1).sToString() << "\n";
    n2 = 4531;
    n3 = n1 / n2;
    std::cout << n1.sToString() << " / " << n2.sToString() << " = " << n3.sToString() << "\n";
    n4 = -5647;
    std::cout << n4.sToString() << " / " << n3.sToString() << " = " << (n4 / n3).sToString() << "\n";
    n5 = n4 * n4;
    std::cout << n4.sToString() << " * " << n4.sToString() << " = " << n5.sToString() << "\n";
    n6 = n5 * n4;
    std::cout << n5.sToString() << " * " << n4.sToString() << " = " << n6.sToString() << "\n";
    n7 = n6 / n4 / n4;
    std::cout << n5.sToString() << " / " << n4.sToString() << " / " << n4.sToString() << " = " << n7.sToString() << "\n";
    std::cout << n7.sToString() << " / 0 = " << (n7 / 0).sToString() << "\n";
}

void vTestModification() {
    std::cout << "\nMODIFICATION TESTS:\n";
    CNumber n, m, k;
    n = 1234;
    int x, y;
    std::cout << "Result of: (y <= (k <= (x <= (m <= n)))): " << (y <= (k <= (x <= (m <= n)))) << "\n";
    std::cout << "k: " << k.sToString() << ", x: " << x << ", m: " << m.sToString() << ", n: " << n.sToString() << "\n";
}
