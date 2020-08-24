//
// Created by a on 8/24/20.
//

#include "test.h"
#include "smartPtr.h"
#include "UniquePtr.h"

struct p{
    int a;
    char b;
};
void test() {

    SmartPtr<int> smp1(new int(5));
    std::cout << *smp1 << std::endl;
    SmartPtr<int> smp2(new int(5));
    std::cout << *smp2 << std::endl;
    std::cout << (smp1 == smp2) << std::endl;
    std::cout << (smp1 != smp2) << std::endl;
    SmartPtr<int> smp3 = smp2;
    SmartPtr<int> smp4;
    smp4 = smp1;


    UniquePtr<int> up1(new int(5));

//    throw exeption:
//    UniquePtr<int> up2 = up1;
//    UniquePtr<int> up3;
//    up3 = up1;

}