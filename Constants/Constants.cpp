#include "Constants.h"

const std::string Constants::compilerCommand = "g++";
const std::string Constants::flags = "-o";
const std::string Constants::exeName = "myProgram";
const std::string Constants::executionCommand = "./" + Constants::exeName;
const std::string Constants::buildCommand = compilerCommand + " \"" + PATH_TO_MAIN + "/main.cpp\" " + flags + " " + exeName;