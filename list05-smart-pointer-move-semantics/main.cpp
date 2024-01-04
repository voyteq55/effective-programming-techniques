#include <iostream>
#include "MySmartPointer.h"

void test(MySmartPointer<std::string> p) {
    std::cout << "some function\n";
}

int main() {
    MySmartPointer<std::string> aaa(new std::string("hello world"));
    
    std::cout << *aaa << "\n";
    std::cout << aaa->length() << "\n";
    
    MySmartPointer<std::string> bbb(new std::string("temporary string"));
    bbb = aaa;
    
    std::transform(bbb->begin(), bbb->end(), bbb->begin(), [](unsigned char c) {
            return std::toupper(c);
        });
    
    std::cout << *aaa << "\n";
    std::cout << aaa->length() << "\n";
    
    test(bbb);
    
    return 0;
}
