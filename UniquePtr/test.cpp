
#include "test.h"
#include "UniquePtr.h"
#include "../utils.h"

struct Inner {
    Inner(int n = 0): _num(n) {}
    int _num;
};

void testUniquePtr::testAll() {
    testCtorAndDtor();
    testOperatorGetData();
}


template<typename T>
void testUniquePtr::checkNull(T* ptr, bool flag) {
    printTest((flag && ptr) || (!flag && !ptr));
}


template<typename T>
void testUniquePtr::checkEqual(T num, T num2, bool flag) {
    printTest((flag && num == num2) || (!flag && num != num2));
}


void testUniquePtr::testCtorAndDtor() {
    std::cout << "\n\n--- ctor and dtor test ---" << std::endl;
    UniquePtr<int> i(new int);
    UniquePtr<int, ArrayDeleter<int> > d(new int);
    std::cout << "test passed" << std::endl;
    std::cout << "---------------------------" << std::endl;
}


void testUniquePtr::testOperatorGetData() {
    std::cout << "\n\n--- operator* test ---" << std::endl;

    UniquePtr<int> i(new int(10));

    checkEqual(*i, 10);
    *i = 8;
    checkEqual(*i, 8);

    std::cout << "---------------------------" << std::endl << std::endl;
    std::cout << "\n\n--- operator-> test ---" << std::endl;

    UniquePtr<Inner> p(new Inner);
    checkEqual(p->_num, 0);

    UniquePtr<Inner> p2(new Inner(8));
    checkEqual(p2->_num, 8);


    std::cout << "---------------------------" << std::endl;
}
