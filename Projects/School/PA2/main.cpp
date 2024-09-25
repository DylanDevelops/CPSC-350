/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include <iostream>
#include "FileInputProcessor.h"
#include "Game.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "[INCORRECT USAGE] Please run program as follows: " << argv[0] << " [INPUT FILE NAME] [OUTPUT FILE NAME]" << std::endl;
        return 1;
    }

    // Seeds the random number generator
    std::srand(std::time(NULL));

    FileInputProcessor fileInputProcessor;
    fileInputProcessor.ReadFile(argv[1]);

    Game game = Game(fileInputProcessor.readValues, argv[2]);

    game.Start();
    
    return 0;
}