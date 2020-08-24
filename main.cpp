#include <iostream>
#include "safePtr/test.h"
#include "UniquePtr/test.h"


int main() {
    testSafePtr test;
    test.testAll();


    testUniquePtr test2;
    test2.testAll();
    return 0;
}