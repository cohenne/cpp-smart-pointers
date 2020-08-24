
#include "test.h"
#include "safePtr.h"


struct Inner {
    Inner(int n = 0): _num(n) {}
    int _num;
};


void printTest(bool result){
    std::cout << (result ? "test passed" : "test failed") << "\n";
}

void testSafePtr::testAll() {
    testCtorAndDtor();
    testCopyCtor();
    testOperatorGetData();
}


template<typename T>
void testSafePtr::checkNull(T* ptr, bool flag) {
    printTest((flag && ptr) || (!flag && !ptr));
}


template<typename T>
void testSafePtr::checkEqual(T num, T num2, bool flag) {
    printTest((flag && num == num2) || (!flag && num != num2));
}


void testSafePtr::testCtorAndDtor() {
    std::cout << "\n\n--- ctor and dtor test ---" << std::endl;
    SafePtr<int> i(new int);
    SafePtr<double> d(new double);
    std::cout << "test passed" << std::endl;
    std::cout << "---------------------------" << std::endl;
}


void testSafePtr::testCopyCtor() {
    std::cout << "\n\n--- copy constructor test ---" << std::endl;

    SafePtr<char> i(new char);
    SafePtr<char> c(i);
    SafePtr<long> ll(new long);
    SafePtr<long> llc(ll);

    checkNull(c.get());
    checkNull(i.get(), false);
    checkNull(llc.get());
    checkNull(ll.get(), false);

    SafePtr<char> b(i);
    checkNull(i.get(), false);
    checkNull(i.get(), false);

    std::cout << "---------------------------" << std::endl;
}


void testSafePtr::testAssignmentOperator() {
    std::cout << "\n\n--- operator= test ---" << std::endl;

    SafePtr<int> i(new int);
    SafePtr<int> j;
    checkNull(j.get(), false);

    j = i;
    checkNull(j.get());
    checkNull(i.get(), false);

    i = j;
    checkNull(i.get());
    checkNull(j.get(), false);

    std::cout << "---------------------------" << std::endl;
}


void testSafePtr::testOperatorGetData() {
    std::cout << "\n\n--- operator* test ---" << std::endl;

    SafePtr<int> i(new int(10));

    checkEqual(*i, 10);
    *i = 8;
    checkEqual(*i, 8);

    std::cout << "---------------------------" << std::endl << std::endl;
    std::cout << "\n\n--- operator-> test ---" << std::endl;

    SafePtr<Inner> p(new Inner);
    checkEqual(p->_num, 0);

    SafePtr<Inner> p2(new Inner(8));
    checkEqual(p2->_num, 8);

    SafePtr<Inner> p3(p2);
    checkEqual(p3->_num, 8);

    std::cout << "---------------------------" << std::endl;
}
