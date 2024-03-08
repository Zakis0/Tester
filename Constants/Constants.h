#ifndef TESTING_CONSTANTS_H
#define TESTING_CONSTANTS_H

#include <string>
#include "../Config.h"

struct Constants {
    const static std::string compilerCommand;
    const static std::string flags;
    const static std::string exeName;

    const static std::string executionCommand;
    const static std::string buildCommand;
};

#endif //TESTING_CONSTANTS_H
