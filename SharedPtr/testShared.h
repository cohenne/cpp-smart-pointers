//
// Created by a on 8/24/20.
//

#ifndef SMART_POINTERS_TESTSHARED_H
#define SMART_POINTERS_TESTSHARED_H


class testSharedPtr {
public:
    void testAll();

    template <typename T>
    void checkNull(T* ptr, bool flag = true);

    template <typename T>
    void checkEqual(T num, T num2, bool flag = true);

    void testCtorAndDtor();

    void testCopyCtor();

    void testAssignmentOperator();

    void testOperatorGetData();

    void phase5();
};


#endif //SMART_POINTERS_TESTSHARED_H
