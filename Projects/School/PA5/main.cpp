/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#include <iostream>
#include <ctime>
#include "RunScareGame.h"

int main(int argc, char* argv[]) {
    // Checks if no input file has been passed in or type
    if(argc != 4) {
        std::cerr << "[ERROR] - You ran the program incorrectly. Please try again with the following usage: '" << argv[0] << " INPUT_FILE.txt OUPUT_FILE.dot [\"double\" or \"single\"]'" << std::endl;
        return 1;
    }
    
    // seeds the random number generator
    std::srand(std::time(0));

    // creates and starts a new game
    RunScareGame* scareGame = new RunScareGame(argv[1], argv[2], argv[3]);
    scareGame->StartTournament();

    // clears up memory
    delete scareGame;

    // Ends main method
    return 0;
}