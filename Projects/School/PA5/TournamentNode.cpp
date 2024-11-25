/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
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
}

// overloaded constructor
TournamentNode::TournamentNode(Monster monster) {
    this->winner = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->monster = monster;
}

// deconstructor
TournamentNode::~TournamentNode() {

}

// method for fights which returns the losing monster
Monster TournamentNode::FightMonster() {
    Monster loser;

    if(left->monster.GetScreamPower() == right->monster.GetScreamPower()) {
        // if they have the same scream power pick a random monster to advance
        int randomNumber = std::rand() % 2;

        // picks a winner based on random chance
        if(randomNumber == 0) {
            winner = left;
        } else if(randomNumber == 1) {
            winner = right;
        }

        // saves the results of the fight
        monster = winner->monster;
        loser = right->monster;

        // returns the loser of the fight
        return loser;
    }

    if(right->hasMonster) {
        // if the right side has a monster
        if(left->monster.ScreamFight(right->monster)) {
            // save data from fight
            winner = left;
            monster = winner->monster;
            loser = right->monster;
        } else {
            // the inverse
            winner = right;
            loser = left->monster;
        }
    } else {
        if(right == nullptr) {
            // if right side has no monster
            winner = left;
            monster = winner->monster;
            loser = Monster();
        }

        // sets results of fight
        winner = left;
        monster = winner->monster;
        loser = right->monster;
    }

    // returns the loser
    return loser;
}