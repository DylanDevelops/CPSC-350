#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {
    std::vector<std::vector<std::string>> board = {
        {"[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]"}
    };

    playGame(board);

    return 0;
}