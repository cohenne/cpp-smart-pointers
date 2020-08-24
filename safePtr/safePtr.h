

#ifndef SMART_POINTERS_SAFEPTR_H
#define SMART_POINTERS_SAFEPTR_H

#include <iostream>

template<class T>
class SafePtr {
public:
    explicit SafePtr(T* ptr=NULL):_ptr(ptr){}
    SafePtr (SafePtr& other):_ptr(other.release()){}
    ~SafePtr() {reset();}
    SafePtr<T>& operator=(SafePtr& other);

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}

    bool operator==(const SafePtr<T>& other)const{return _ptr == other._ptr;}
    bool operator!=(const SafePtr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset(T* ptr=NULL);

private:
    T* _ptr;
};


#include "safePtr.hpp"


#endif //SMART_POINTERS_SAFEPTR_H
