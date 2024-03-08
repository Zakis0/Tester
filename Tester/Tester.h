#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

#include <cstdio>

#include "../Constants/Constants.h"
#include "../Builder/Builder.h"
#include "../TestList/TestList.h"

struct Tester {
    static bool startTest(int index, bool compile = false);
    static void startAllTests();
};


#endif //TESTER_TESTER_H
