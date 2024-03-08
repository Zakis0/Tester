#include "Tester.h"

bool Tester::startTest(int index, bool compile) {
    if (compile) {
        Builder::compile(true);

    }
    std::string output = Builder::readOutput(TestList::tests[index].input);

    trimLineBreaks(output);

    if (output != TestList::tests[index].output || compile) {
        std::cout << "Test index: " << index << std::endl;
        std::cout << TestList::tests[index].input << std::endl;
        std::cout << "Res: " << output << std::endl;
        std::cout << "Correct: " << TestList::tests[index].output << std::endl;
        return false;
    }
    return true;
}

void Tester::startAllTests() {
    Builder::compile(true);
    int counterOfBadTests = 0;
    for (int i = 0; i < TestList::tests.size(); ++i) {
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
