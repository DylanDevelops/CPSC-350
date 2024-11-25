/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#ifndef TOURNAMENT_NODE_H
#define TOURNAMENT_NODE_H

#include "Monster.h"
#include <iostream>

class TournamentNode {
    public:
        // constructors and destructors
        TournamentNode();
        TournamentNode(Monster monster);
        ~TournamentNode();

        // methods
        Monster FightMonster();

        // variables
        TournamentNode* left;
        TournamentNode* right;
        Monster monster;
        bool hasMonster;

    private:
        TournamentNode* winner;
};

#endif