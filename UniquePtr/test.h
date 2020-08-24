//
// Created by a on 8/24/20.
//

#ifndef SMART_POINTERS_TEST_H
#define SMART_POINTERS_TEST_H

#include <iostream>

class testUniquePtr {
public:
    void testAll();

    template <typename T>
    void checkNull(T* ptr, bool flag = true);

    template <typename T>
    void checkEqual(T num, T num2, bool flag = true);

    void testCtorAndDtor();

    void testOperatorGetData();
};





#endif //SMART_POINTERS_TEST_H
