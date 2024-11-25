/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#include "TournamentNode.h"

// default constructor
TournamentNode::TournamentNode() {
    this->winner = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->monster = Monster();
    this->hasMonster = false;
}

// overloaded constructor
TournamentNode::TournamentNode(Monster monster) {
    this->winner = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->monster = monster;
    this->hasMonster = true;
}

// deconstructor
TournamentNode::~TournamentNode() {

}

// method for fights which returns the losing monster
Monster TournamentNode::FightMonster() {
    Monster loser;

    if (left == nullptr || right == nullptr) {
        // return a monster here so there is no seg fault
        return Monster();
    }

    if(left->monster.GetScreamPower() == right->monster.GetScreamPower()) {
        // if they have the same scream power pick a random monster to advance
        int randomNumber = std::rand() % 2;

        // picks a winner based on random chance
        if(randomNumber == 0) {
            winner = left;
            loser = right->monster;
        } else {
            winner = right;
            loser = left->monster;
        }
    } else if(left->monster.ScreamFight(right->monster)) {
        // save data from fight
        winner = left;
        loser = right->monster;
    } else {
        // the inverse
        winner = right;
        loser = left->monster;
    }

    // sets results of fight
    monster = winner->monster;

    // returns the loser
    return loser;
}