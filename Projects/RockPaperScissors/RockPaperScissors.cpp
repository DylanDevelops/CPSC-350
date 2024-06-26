#include <iostream>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int computer = rand() % 3 + 1;
    int user = 0;
    bool userWon = false;

    std::cout << "====================" << std::endl;
    std::cout << "rock paper scissors!" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "1) ✊" << std::endl;
    std::cout << "2) ✋" << std::endl;
    std::cout << "3) ✌️" << std::endl;

    std::cout << "shoot! ";

    std::cin >> user;

    switch(user) {
        case 1:
            std::cout << "You chose: ✊" << std::endl;
            break;
        case 2:
            std::cout << "You chose: ✋" << std::endl;
            break;
        case 3:
            std::cout << "You chose: ✌️" << std::endl;
            break;
    }

    switch(computer) {
        case 1:
            std::cout << "The computer chose: ✊" << std::endl;
            break;
        case 2:
            std::cout << "The computer chose: ✋" << std::endl;
            break;
        case 3:
            std::cout << "The computer chose: ✌️" << std::endl;
            break;
    }

    if(user == 1 && computer == 3) {
        userWon = true;
    } else if(user == 2 && computer == 1) {
        userWon = true;
    } else if(user == 3 && computer == 1) {
        userWon = true;
    }

    if(user == computer) {
        std::cout << "It's a tie!" << std::endl;
    } else if(userWon) {
        std::cout << "You won!" << std::endl;
    } else {
        std::cout << "You lost!" << std::endl;
    }

    return 0;
}