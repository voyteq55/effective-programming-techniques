#include <iostream>
#include "Pointer.h"

int main() {
    int* p1 = new int(81);
    std::string* p2 = new std::string("abc");
    
    int i = 10;
    
    Pointer<int*> pointer1(p1);
    Pointer<std::string*> pointer2(p2);
    
//    Pointer<int> invalidPointer1(100);
//    Pointer<std::string&> invalidPointer2(i);
    
    std::cout << *pointer1 << "\n";
    std::cout << *pointer2 << "\n";
    return 0;
}
