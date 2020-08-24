#include "safePtr.h"


template<class T>
inline SafePtr<T>& SafePtr<T>:: operator=(SafePtr& other){
    if(this != &other){
        reset(other.release());
    }

    return *this;
}



template<class T>
inline T* SafePtr<T>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


template<class T>
inline void SafePtr<T>::reset(T *ptr) {
    if(_ptr != ptr){
        delete _ptr;
        _ptr = ptr;
    }
}