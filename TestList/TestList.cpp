#include "TestList.h"

std::vector<Test> TestList::tests = {
        Test("0 7\n"
             "12 3",
             "22"
        ),
        Test("0 7\n"
             "11 5",
             "24"
        ),
        Test("0 7\n"
             "12 5",
             "25"
        ),
        Test("0 7\n"
             "13 5",
             "26"
        ),
        Test("100 50\n"
             "1 0",
             "102"
        ),
        Test("100 50\n"
             "50 0",
             "101"
        ),
        Test("100 0\n"
             "50 0",
             "2"
        ),
};
