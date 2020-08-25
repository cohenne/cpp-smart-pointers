

#ifndef SMART_POINTERS_UNIQUEPTR_H
#define SMART_POINTERS_UNIQUEPTR_H

#include "Deleter.h"
#include "../utils.h"


template <class T, class D = DefualtDelete<T> >
class UniquePtr: private Uncopyable{

public:
    typedef D deleteType;

    explicit UniquePtr<T, D>(T* ptr=NULL): _ptr(ptr){}
    ~UniquePtr() {reset();}

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}

    T* release();
    void reset(T* ptr=NULL);
    void swap(UniquePtr& ptr);

private:
    T* _ptr;
};


#include "UniquePtr.hpp"

#endif //SMART_POINTERS_UNIQUEPTR_H
