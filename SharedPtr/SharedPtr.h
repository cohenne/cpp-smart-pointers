
#ifndef SMART_POINTERS_SHAREDPTR_H
#define SMART_POINTERS_SHAREDPTR_H

#include <iostream>

template<class T>
class Shared_Ptr{
public:
    explicit Shared_Ptr(T* ptr=NULL):_ptr(ptr), _count(new size_t(1)){}
    Shared_Ptr(Shared_Ptr& other):_ptr(other._ptr()), _count(other._count){ incCount();}
    ~Shared_Ptr() {lastPointer();}
    Shared_Ptr& operator=(Shared_Ptr& other);

    T* get()        const {return _ptr;}
    T& operator* () const {return *_ptr;}
    T* operator->() const {return _ptr;}
    operator bool() const { return _ptr;}


    size_t* getCount() const{ return _count;}

//    bool operator==(const Shared_Ptr<T>& other)const{return _ptr == other._ptr;}
//    bool operator!=(const Shared_Ptr<T>& other)const{return _ptr != other._ptr;}

    T* release();
    void reset(T* ptr=NULL);
//    void swap(Shared_Ptr<T>&);
//    long int use_count()const;
    bool unique()const{ return 1 == _count;}
//    bool owner_befor (const Shared_Ptr<T>&)const;

private:
    T* _ptr;
    size_t* _count;

    void decCount(){(*_count)--;}
    void incCount(){(*_count)++;}
    void lastPointer();
};


template<class T>
inline Shared_Ptr<T>& Shared_Ptr<T>:: operator=(Shared_Ptr& other){
    if(*this != other){
        lastPointer();
        _ptr = other.getPtr();
        _count = other.getCount();
        incCount();
    }

    return *this;
}



template<class T>
inline T* Shared_Ptr<T>::release(){
    T* temp = _ptr;
    _ptr = NULL;
    return temp;
}


//template<class T>
//inline void SmartPtr<T>::reset(T *ptr) {
//    if(_ptr != ptr){
//        delete _ptr;
//        _ptr = ptr;
//    }
//}
template <class T>
inline void Shared_Ptr<T>::lastPointer(){
    if(_count != NULL){
        decCount();
        if(0 == *_count){
            delete _count;
            delete _ptr;
        }
    }
}


#endif //SMART_POINTERS_SHAREDPTR_H
