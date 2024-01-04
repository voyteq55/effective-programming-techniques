#ifndef MYREFCOUNTER_H
#define MYREFCOUNTER_H

class MyRefCounter {
public:
    MyRefCounter();
    
    int increase();
    int decrease();
    int get();
    
private:
    int refCount;
};

#endif
