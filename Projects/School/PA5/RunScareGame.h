/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#ifndef RUN_SCARE_GAME_H
#define RUN_SCARE_GAME_H

#include <iostream>
#include <vector>
#include "TournamentTree.h"

class RunScareGame {
    public:
        // constructors and destructors
        RunScareGame();
        RunScareGame(std::string inputFile, std::string outputFile, std::string gameType);
        ~RunScareGame();

        // methods
        void StartTournament();        

    private:
        // variables
        std::string inputFile;
        std::string outputFile;
        std::string gameType;
};

#endif