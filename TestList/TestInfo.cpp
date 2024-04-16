#include "TestInfo.h"

const std::string TestInfo::PATH_TO_MAIN =
"/home/zakis/Code/sportsProgramming/YandexAlgorithms5_0/2/J. Two rectangles/main.cpp";

std::vector<Test> TestInfo::tests = {
        Test("3 2\n"
             "#.\n"
             "##\n"
             ".#",
             "YES\n"
             "a.\n"
             "ab\n"
             ".a"
        ),
        Test("2 4\n"
             ".#..\n"
             "###.",
             "YES\n"
             ".b..\n"
             "aaa."
        ),
        Test("4 2\n"
             "..\n"
             "##\n"
             ".#\n"
             "..",
             "YES\n"
             "..\n"
             "ba\n"
             ".a\n"
             ".."
        ),
        Test("4 4\n"
             "....\n"
             "##..\n"
             "###.\n"
             ".##.",
             "NO"
        ),
        Test("3 5\n"
             ".....\n"
             ".###.\n"
             ".###.",
             "YES\n"
             ".....\n"
             ".bbb.\n"
             ".aaa."
        ),
        Test("2 1\n"
             "#\n"
             ".",
             "NO"
        ),
        Test("2 2\n"
             "..\n"
             "##",
             "YES\n"
             "..\n"
             "ba"
        ),
        Test("1 3\n"
             "###",
             "YES\n"
             "baa"
        ),
        Test("1 5\n"
             "####.",
             "YES\n"
             "baaa."
        ),
};