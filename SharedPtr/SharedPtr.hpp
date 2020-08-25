#include "SharedPtr.h"

template<class T>
Shared_Ptr<T>::Shared_Ptr(Shared_Ptr& other) : _ptr(other.m_ptr), _count(other.m_count) {
    if(_count) {
       incCount();
    }
}

template <class T>
template <class U>
Shared_Ptr<T>::Shared_Ptr(const Shared_Ptr<U>& other) : _ptr(other.m_ptr) {
    _count = *(size_t**)((char *)&other + sizeof(T*));
    if(_count) {
        incCount();
    }
}


template<class T>
inline Shared_Ptr<T>& Shared_Ptr<T>:: operator=(const Shared_Ptr& other){
    if(*this != other){
        reset();
        _ptr = other.get();
        _count = other._count;
        incCount();
    }

    return *this;
}

template<class T>
template <class U>
inline Shared_Ptr<T>& Shared_Ptr<T>:: operator=(const Shared_Ptr<U>& other){
    if(*this != other){
        reset();
        _ptr = other.get();
        _count = *(size_t**)((char *)&other + sizeof(T*));
        incCount();
    }

    return *this;
}

template<class T>
void Shared_Ptr<T>::deallocate() {
    if(*_count == 0 && _ptr) {
        delete _ptr;
        delete _count;
    }
    _ptr = NULL;
    _count = NULL;
}


template<class T>
inline T* Shared_Ptr<T>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


template<class T>
void Shared_Ptr<T>::reset() {
    if(_count) {
        decCount();
        deallocate();
    }
}
​
template<class T>
void Shared_Ptr<T>::reset(T *ptr) {
    reset();
    if(ptr) {
        _ptr = ptr;
        _count = new size_t(1);
    }
}