#include "Test.h"

Test::Test(std::string input, std::string output) {
    this->input = std::move(input);
    this->output = std::move(output);
}