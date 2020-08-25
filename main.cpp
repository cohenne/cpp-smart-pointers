
#include "safePtr/test.h"
#include "UniquePtr/testUnique.h"
#include "SharedPtr/testShared.h"

int main() {

    std::cout<<"\n\n-------------- test SafePtr ----------------";
    testSafePtr test;
    test.testAll();

    std::cout<<"\n\n-------------- test UniquePtr ----------------";
    testUniquePtr test2;
    test2.testAll();

    std::cout<<"\n\n-------------- test SharedPtr ----------------";
    testSharedPtr test3;
    test3.testAll();
    return 0;
}