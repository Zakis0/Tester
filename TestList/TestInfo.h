#ifndef TESTING_TESTS_H
#define TESTING_TESTS_H

#include <vector>
#include "../Test/Test.h"

struct TestInfo {
    const static std::string PATH_TO_MAIN;
    static std::vector<Test> tests;
};

#endif //TESTING_TESTS_H
