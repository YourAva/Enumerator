#include <iostream>
#include <string>

#define okay(msg, ...) printf("\033[1;92m[+] " msg "\033[0;0m\n", ##__VA_ARGS__)
#define info(msg, ...) printf("\033[1;96m[i] " msg "\033[0;0m\n", ##__VA_ARGS__)
#define breaker() printf("\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[1;95m-\033[1;96m-\033[0;0m\n")
#define warn(msg, ...) printf("\033[1;91m[-] " msg "\033[0;0m\n", ##__VA_ARGS__)

std::string concatenateArguments(std::string argString, std::string newArg) {
    argString = argString + " " + newArg;
    return argString;
}

void printTitle() {
    std::cout << "\033[1;35m ____  _      _     _      ____  ___    __   _____  ___   ___  \n| |_  | |\\ | | | | | |\\/| | |_  | |_)  / /\\   | |  / / \\ | |_) \n|_|__ |_| \\| \\_\\_/ |_|  | |_|__ |_| \\ /_/--\\  |_|  \\_\\_/ |_| \\ \033[0;0m";
    info("nMap Wrapper By Platypus");
    std::cout << "\n\n";
    info("All nMap documentation can be found here. This is just a wrapper program and has no links to the original nMap program or its contributors : https://nmap.org/");
    std::cout << "\n\n";
}

void initialScan(std::string ip, std::string args) {
    info("Beginning initial enumeration to identify open ports...");
    
    std::string syscall = "nmap -v -p- -oN /tmp/tempEnumerationOutput " + ip + " " + args;

    breaker();
    system(syscall.c_str());
    breaker();

    system("grep open /tmp/tempEnumerationOutput | awk '{print $1}' | cut -d '/' -f 1 | awk '{print $0 \",\"}' | tr --delete '\\n' > /tmp/openPortsList");

    okay("Initial scanning done and saved to /tmp/openPortsList. This will be cleared when your device powers down.");
}

void deepScan(std::string ip, std::string args) {
    info("Beginning deeper scan into open ports...");

    // Pretty sure this needs to be ran in root. Fix that if there's any problems with this comamnd.
    std::string syscall = "nmap -v -sC -sV -oN ./enmOut -T4 " + ip + " -p $(cat /tmp/openPortsList) " + args;
    
    breaker();
    system(syscall.c_str());
    breaker();

    okay("Final scan has been complete. A file named enumeratorOutput has been added to this filespace for you to read and check for information.");
}