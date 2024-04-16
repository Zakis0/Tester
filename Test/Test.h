#ifndef TESTING_TEST_H
#define TESTING_TEST_H

#include <iostream>

struct Test {
    std::string input;
    std::string expectedOutput;
    Test(std::string input, std::string expectedOutput);
};

#endif //TESTING_TEST_H
