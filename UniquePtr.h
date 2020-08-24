//
// Created by a on 8/23/20.
//

#ifndef SMART_POINTERS_UNIQUEPTR_H
#define SMART_POINTERS_UNIQUEPTR_H

#include "smartPtr.h"

template <typename T>
class UniquePtr: public SmartPtr<T> {

public:
    explicit UniquePtr(T* ptr=NULL): SmartPtr<T>(ptr){}

private:
    UniquePtr(const UniquePtr<T>& other);
    UniquePtr<T>& operator=(const UniquePtr<T>& other);

};


#endif //SMART_POINTERS_UNIQUEPTR_H
