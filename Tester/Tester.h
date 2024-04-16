#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

#include <cstdio>

#include "../Constants/Constants.h"
#include "../Builder/Builder.h"
#include "../TestList/TestInfo.h"

struct Tester {
    static bool startTest(int index, bool compile = false);
    static void startAllTests();

private:
    static void trimLineBreaks(std::string& str);
};


#endif //TESTER_TESTER_H
