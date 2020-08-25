
#ifndef SMART_POINTERS_SHAREDPTR_H
#define SMART_POINTERS_SHAREDPTR_H

#include <iostream>
#include "Deleter.h"

template<class T/*, class D = DefualtDelete<T>*/ >
class Shared_Ptr{
public:
//    typedef D deleteType;

    Shared_Ptr<T>():_ptr(NULL), _count(NULL){}
    explicit Shared_Ptr<T>(T* ptr):_ptr(ptr), _count(new size_t(1)){}
    ~Shared_Ptr() {reset();}

    Shared_Ptr (Shared_Ptr& other);
    template <class U>
    Shared_Ptr(const Shared_Ptr<U>& other);


    Shared_Ptr<T>& operator=(const Shared_Ptr& other);
    template <typename U>
    Shared_Ptr<T>& operator=(const Shared_Ptr<U>& other);

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}
    explicit operator bool() const { return _ptr;}


    size_t* getCount() const{ return _count;}

    bool operator==(const Shared_Ptr<T>& other)const{return _ptr == other._ptr;}
    bool operator!=(const Shared_Ptr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset();
    void reset (T* ptr);


    //    void swap(Shared_Ptr<T>&);
//    long int use_count()const;
    bool unique()const{ return _count && 1 == *_count;}
//    bool owner_befor (const Shared_Ptr<T>&)const;

private:
    T* _ptr;
    size_t* _count;

    void deallocate();
    void decCount(){--(*_count);}
    void incCount(){++(*_count);}
};


#include "SharedPtr.hpp"


#endif //SMART_POINTERS_SHAREDPTR_H
