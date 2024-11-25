/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#ifndef TOURNAMENT_TREE_H
#define TOURNAMENT_TREE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "TournamentNode.h"

class TournamentTree {
    public:
        // constructors and destructors
        TournamentTree();
        TournamentTree(TournamentNode* root);
        TournamentTree(std::vector<Monster> monsterBracket);
        TournamentTree(std::string file);
        ~TournamentTree();

        // variables
        TournamentNode* root;
        std::vector<Monster> finals;
        std::vector<Monster> monsterLosersBracket;

        // methods
        void CreateTournamentTree(std::vector<Monster> monsterBracket);
        Monster SingleElimination();
        Monster DoubleElimination();
        Monster DoubleEliminationWinner();
        void SaveTreeAsDot(const std::string& fileName, TournamentNode* rootNode);
    private:
        // variables
        std::vector<Monster> monsterBracket;
        std::ifstream fileReader;
        std::string fileName;
        int monsterBracketSize;


        // helper methods
        void HelpCreateTournamentTree(TournamentNode*& rootNode, int& currentSize, int currentPowerLevel, std::vector<Monster>& monsterBracket, int& index);
        void HelpTournament(TournamentNode* rootNode);
        void SaveTreeAsDotHelper(TournamentNode* node, std::ofstream& fileStream, int& nodeNumber);
};

#endif