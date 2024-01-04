#ifndef MYSMARTPOINTER_H
#define MYSMARTPOINTER_H

#include "MyRefCounter.h"
#include <iostream>

template <typename T>
class MySmartPointer {
public:
    MySmartPointer(T* pointer);
    MySmartPointer(const MySmartPointer<T>& other);
    ~MySmartPointer();
    
    MySmartPointer& operator=(const MySmartPointer<T>& other);
    T& operator*() const;
    T* operator->() const;
    
private:
    void createPointer(const MySmartPointer<T>& other);
    void deallocate();
    
    T* pointer;
    MyRefCounter* refCounter;
};

template <typename T>
MySmartPointer<T>::MySmartPointer(T* pointer): pointer(pointer) {
    refCounter = new MyRefCounter();
    refCounter->increase();
    std::cout << *pointer << ": created new pointer with count " << refCounter->get() << "\n";
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer<T>& other) {
    createPointer(other);
    std::cout << *pointer << ": copied pointer from const., count: " << refCounter->get() << "\n";
}

template <typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer<T> &other) {
    if (this != &other) {
        std::cout << *pointer << ": removing reassigned pointer, count before removing: " << refCounter->get() << "\n";
        if (refCounter != nullptr && refCounter->decrease() == 0) {
            deallocate();
        }
        createPointer(other);
    }
    std::cout << *pointer << ": copied pointer with '=', count: " << refCounter->get() << "\n";
    return *this;
}

template <typename T>
MySmartPointer<T>::~MySmartPointer() {
    std::cout << *pointer << ": removing pointer not in scope, count before removing: " << refCounter->get() << "\n";
    if (refCounter->decrease() == 0) {
        deallocate();
    }
}

template <typename T>
T& MySmartPointer<T>::operator*() const {
    return *pointer;
}

template <typename T>
T* MySmartPointer<T>::operator->() const {
    return pointer;
}

template <typename T>
void MySmartPointer<T>::createPointer(const MySmartPointer<T> &other) {
    pointer = other.pointer;
    refCounter = other.refCounter;
    refCounter->increase();
}

template <typename T>
void MySmartPointer<T>::deallocate() {
    std::cout << *pointer << ": pointer not in use\n";
    delete pointer;
    delete refCounter;
}

#endif
