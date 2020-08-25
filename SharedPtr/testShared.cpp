//
// Created by a on 8/24/20.
//

#include "testShared.h"
#include "SharedPtr.h"
#include "../utils.h"

struct Inner {
    Inner(int n = 0): _num(n) {}
    int _num;
};

class A
{
    int a;
};
class B: public A
{
    int b;
};

void testSharedPtr::testAll() {
    testCtorAndDtor();
    testCopyCtor();
    testOperatorGetData();
//    phase5();
}


template<typename T>
void testSharedPtr::checkNull(T* ptr, bool flag) {
    printTest((flag && ptr) || (!flag && !ptr));
}


template<typename T>
void testSharedPtr::checkEqual(T num, T num2, bool flag) {
    printTest((flag && num == num2) || (!flag && num != num2));
}


void testSharedPtr::testCtorAndDtor() {
    std::cout << "\n\n--- ctor and dtor test ---" << std::endl;
    Shared_Ptr<int> i(new int);
    Shared_Ptr<double> d(new double);
    std::cout << "test passed" << std::endl;
    std::cout << "---------------------------" << std::endl;
}


void testSharedPtr::testCopyCtor() {
    std::cout << "\n\n--- copy constructor test ---" << std::endl;

    Shared_Ptr<char> i(new char);
    Shared_Ptr<char> c(i);
//    Shared_Ptr<long> ll(new long);
//    Shared_Ptr<long> llc(ll);
//
//    checkNull(c.get());
//    checkNull(i.get(), false);
//    checkNull(llc.get());
//    checkNull(ll.get(), false);
//
//    Shared_Ptr<char> b(i);
//    checkNull(i.get(), false);
//    checkNull(i.get(), false);

    std::cout << "---------------------------" << std::endl;
}


void testSharedPtr::testAssignmentOperator() {
    std::cout << "\n\n--- operator= test ---" << std::endl;

    Shared_Ptr<int> i(new int);
    Shared_Ptr<int> j;
    checkNull(j.get(), false);

    j = i;
    checkNull(j.get());
    checkNull(i.get(), false);

    i = j;
    checkNull(i.get());
    checkNull(j.get(), false);

    std::cout << "---------------------------" << std::endl;
}


void testSharedPtr::testOperatorGetData() {
    std::cout << "\n\n--- operator* test ---" << std::endl;

    Shared_Ptr<int> i(new int(10));

    checkEqual(*i, 10);
    *i = 8;
    checkEqual(*i, 8);

    std::cout << "---------------------------" << std::endl << std::endl;
    std::cout << "\n\n--- operator-> test ---" << std::endl;

    Shared_Ptr<Inner> p(new Inner);
    checkEqual(p->_num, 0);

    Shared_Ptr<Inner> p2(new Inner(8));
    checkEqual(p2->_num, 8);

    Shared_Ptr<Inner> p3(p2);
    checkEqual(p3->_num, 8);

    std::cout << "---------------------------" << std::endl;
}

void testSharedPtr::phase5(){
    Shared_Ptr<A>a(new A);
    Shared_Ptr<B>b(new B);
    a=b;
    printTest((a==b));
}