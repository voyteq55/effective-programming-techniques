#include "MyRefCounter.h"

MyRefCounter::MyRefCounter(): refCount(0) {}

int MyRefCounter::increase() {
    return ++refCount;
}

int MyRefCounter::decrease() {
    return --refCount;
}

int MyRefCounter::get() {
    return refCount;
}
