#include <iostream>
#include <string>
#include "functions.hpp"

int main() {
    std::string word = "broccoli", text = "I sometimes eat broccoli. There are three interesting things about broccoli. Number One. Nobody knows how to spell it. Number Two. No matter how long you boil it, it's always cold by the time it reaches your plate. Number Three. It's green. #broccoli";

    std::cout << "\nBefore:\n" << text << std::endl;

    bleep(word, text);

    std::cout << "\nAfter:\n" << text << std::endl;

    std::cout << "\nFiltered Word: \"" << word << "\"" << std::endl;
}