#include "TestList.h"

std::vector<Test> TestList::tests = {
        Test("0:0\n"
             "0:0\n"
             "1",
             "1"
        ),
        Test("0:2\n"
             "0:3\n"
             "1",
             "5"
        ),
        Test("0:2\n"
             "0:3\n"
             "2",
             "6"
        ),
};
