#include <iostream>

#include <lexer.hpp>
#include <types.hpp>

String Username = "Unknown";
String Input = "";
String Prefix = "\x1b[38;2;5;163;242m~>\x1b[97m ";

Map<String, String> Context = {};

int main() {
    while (1) {
        std::cout << Prefix;
        std::getline(std::cin, Input);
        std::cout << "\x1b[0m";
        
        Execute(Analize(Input));
    }
}