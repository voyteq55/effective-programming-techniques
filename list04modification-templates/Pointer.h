#ifndef POINTER_H
#define POINTER_H

template <typename T>
class Pointer;

template <typename T>
class Pointer<T*> {
public:
    Pointer(T* value): val(value) {}
    
    T operator*() {
        return *val;
    }
    
private:
    T* val;
};

#endif
