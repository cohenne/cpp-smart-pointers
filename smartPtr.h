//
// Created by a on 8/8/20.
//

#ifndef SMART_POINTERS_SMARTPTR_H
#define SMART_POINTERS_SMARTPTR_H

#include <iostream>

template<class T>
class SmartPtr {
public:
    explicit SmartPtr(T* ptr=NULL):_ptr(ptr){}
    SmartPtr(SmartPtr& other):_ptr(other.release()){}
    ~SmartPtr() {reset();}
    SmartPtr& operator=(SmartPtr& other);

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}

    bool operator==(const SmartPtr<T>& other)const{return _ptr == other._ptr;}
    bool operator!=(const SmartPtr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset(T* ptr=NULL);

private:
    T* _ptr;
};


template<class T>
inline SmartPtr<T>& SmartPtr<T>:: operator=(SmartPtr& other){
    if(this != &other){
        delete _ptr;
        _ptr = other.release();
    }

    return *this;
}



template<class T>
inline T* SmartPtr<T>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


template<class T>
inline void SmartPtr<T>::reset(T *ptr) {
    if(_ptr != ptr){
        delete _ptr;
        _ptr = ptr;
    }
}

#endif //SMART_POINTERS_SMARTPTR_H
