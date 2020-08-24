//
// Created by a on 8/24/20.
//

#ifndef SMART_POINTERS_DELETER_H
#define SMART_POINTERS_DELETER_H

#include <iostream>


template<class T>
struct DefualtDelete{
    static void release(T* ptr=NULL){
        if (ptr) {
            delete ptr;
            ptr = NULL;
        }
    }
};


template<class T>
struct ArrayDeleter{
    static void release(T* ptr=NULL){
        if (ptr) {
            delete [] ptr;
            ptr = NULL;
        }
    }
};

#endif //SMART_POINTERS_DELETER_H
