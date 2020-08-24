//
// Created by a on 8/23/20.
//

#ifndef SMART_POINTERS_UNIQUEPTR_H
#define SMART_POINTERS_UNIQUEPTR_H

#include "../safePtr/safePtr.h"

template <typename T>
class UniquePtr: public SafePtr<T> {

public:
    explicit UniquePtr(T* ptr=NULL): SafePtr<T>(ptr){}

private:
    UniquePtr(const UniquePtr<T>& other);
    UniquePtr<T>& operator=(const UniquePtr<T>& other);

};


#endif //SMART_POINTERS_UNIQUEPTR_H
