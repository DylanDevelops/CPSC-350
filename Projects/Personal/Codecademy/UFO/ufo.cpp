#include <utility>
#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

int main() {

    std::pair<std::string, std::string> wordAndAnswer = getWordAndAnswer();
    std::string codeword = wordAndAnswer.first;
    std::string answer = wordAndAnswer.second;

    int misses = 0;

    greet();

    std::vector<char> incorrect;
    bool guess = false;

    char letter;

    while(answer != codeword && misses < 7) {
        display_misses(misses);

        display_status(answer, incorrect);

        std::cout << "Please enter your guess: ";
        std::cin >> letter;

        for(int i = 0; i < codeword.length(); i++) {
            if(letter == codeword[i]) {
            answer[i] = letter;
            guess = true;
            }
        }

        if(guess) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect! The tractor beam pulls the person in further." << std::endl;
            incorrect.push_back(letter);

            misses++;
        }

        guess = false;
    }

    end_game(answer, codeword);
}
