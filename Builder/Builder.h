#ifndef TESTER_BUILDER_H
#define TESTER_BUILDER_H

#include <iostream>
#include <csignal>
#include <cstring>
#include <sys/wait.h>

#include "../Constants/Constants.h"
#include "../Config.h"

struct Builder {
    static int compile(bool debug = false);
    static int execute();
    static int compileAndExecute();
    static std::string readOutput(const std::string& input = "");
};


#endif //TESTER_BUILDER_H
