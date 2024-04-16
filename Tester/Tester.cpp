#include "Tester.h"

bool Tester::startTest(int index, bool compile) {
    if (compile) {
        Builder::compile(true);

    }
    std::string output = Builder::readOutput(TestInfo::tests[index].input);

    trimLineBreaks(output);

    if (output != TestInfo::tests[index].expectedOutput || compile) {
        std::cout << "Test index: " << index << std::endl;
        std::cout << "Program input:" << std::endl << TestInfo::tests[index].input << std::endl << std::endl;
        std::cout << "Program output:" << std::endl << output << std::endl << std::endl;
        std::cout << "Expected output:" << std::endl << TestInfo::tests[index].expectedOutput << std::endl;
        return false;
    }
    return true;
}

void Tester::startAllTests() {
    Builder::compile(true);
    int counterOfBadTests = 0;
    for (int i = 0; i < TestInfo::tests.size(); ++i) {
        if (!startTest(i)) {
            ++counterOfBadTests;
            std::cout << WRONG_TESTS_DELIMITER << std::endl;
        }
    }
    if (counterOfBadTests == 0) {
        std::cout << "All tests passed!" << std::endl;
    }
}

void Tester::trimLineBreaks(std::string& str) {
    while (!str.empty() && (str.back() == '\n' || str.back() == '\r')) {
        str.pop_back();
    }
}
