

#ifndef SMART_POINTERS_TEST_H
#define SMART_POINTERS_TEST_H

class testSafePtr {
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
};



#endif //SMART_POINTERS_TEST_H
