#include "UniquePtr.h"

template<class T, class D>
inline T* UniquePtr<T, D>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


template<class T, class D>
inline void UniquePtr<T, D>::reset(T* ptr) {
    if(_ptr != ptr){
        if(_ptr){
            UniquePtr<T, D>::deleteType ::release(_ptr);
        }
        _ptr = ptr;
    }
}