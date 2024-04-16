cmake_minimum_required(VERSION 3.27)
project(Tester)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tester main.cpp
        TestList/TestInfo.h
        Test/Test.cpp
        Test/Test.h
        Constants/Constants.cpp
        Constants/Constants.h
        Tester/Tester.cpp
        Tester/Tester.h
        Builder/Builder.cpp
        Builder/Builder.h
        Config.h
        TestList/TestInfo.cpp
)
