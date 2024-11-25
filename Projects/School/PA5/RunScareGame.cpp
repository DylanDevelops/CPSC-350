/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#include "RunScareGame.h"

// default constructor
RunScareGame::RunScareGame() {
    this->inputFile = "";
    this->outputFile = "";
    this->gameType = "";
}

// overloaded constructor
RunScareGame::RunScareGame(std::string inputFile, std::string outputFile, std::string gameType) {
    this->inputFile = inputFile;
    this->outputFile = outputFile;
    this->gameType = gameType;
}

// destructor
RunScareGame::~RunScareGame() {
    
}

// Play out the tournament
void RunScareGame::StartTournament() {
    if (gameType == "single") {
        // If it is a single game type

        // plays a single elimination
        TournamentTree gameTree(inputFile);
        gameTree.SingleElimination();

        // Saves game to a dot file
        gameTree.SaveTreeAsDot(outputFile, gameTree.root);
    } else if (gameType == "double") {
        // If it is a double game type

        // plays a single elimination
        TournamentTree gameTree(inputFile);
        gameTree.SingleElimination();

        // Plays loser bracket game
        TournamentTree doubleTree(gameTree.monsterLosersBracket);
        doubleTree.DoubleElimination();

        // Finishs tournament
        TournamentNode* root = new TournamentNode();
        root->left = gameTree.root;
        root->right = doubleTree.root;
        root->FightMonster();

        // Saves the finals to a dot file
        TournamentTree finals(root);
        finals.SaveTreeAsDot(outputFile, root);
    }
}
