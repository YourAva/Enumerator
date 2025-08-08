#include <stdio.h>
#include <string>
#include "header.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        warn("Argument set incorrectly!\n\nenumerator {ip}");
        return 1;
    }

    std::string argString;

    for (int i = 2; i < argc; i++) {
        argString = concatenateArguments(argString, argv[i]);
    }

    printTitle();
    initialScan(argv[1], argString);
    deepScan(argv[1], argString);
}