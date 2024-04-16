#include "Test.h"

Test::Test(std::string input, std::string expectedOutput) {
    this->input = std::move(input);
    this->expectedOutput = std::move(expectedOutput);
}