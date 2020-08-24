//
// Created by a on 8/23/20.
//

#ifndef SMART_POINTERS_UNIQUEPTR_H
#define SMART_POINTERS_UNIQUEPTR_H

#include "../safePtr/safePtr.h"
#include "Deleter.h"


class Uncopyable{
protected:
    Uncopyable(){}
    ~Uncopyable(){}

private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator= (const Uncopyable&);
};


template <class T, class D = DefualtDelete<T> >
class UniquePtr: private Uncopyable{

public:
    typedef D deleteType;


    explicit UniquePtr<T, D>(T* ptr=NULL): _ptr(ptr){}
    ~UniquePtr() {reset();}

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}

//    bool operator==(const SafePtr<T>& other)const{return _ptr == other._ptr;}
//    bool operator!=(const SafePtr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset(T* ptr=NULL);
    void swap(UniquePtr& ptr);

private:
    T* _ptr;

    UniquePtr<T, D>(const UniquePtr<T, D>& );
    UniquePtr<T, D>& operator=(const UniquePtr<T, D>& );

};


#include "UniquePtr.hpp"

#endif //SMART_POINTERS_UNIQUEPTR_H
