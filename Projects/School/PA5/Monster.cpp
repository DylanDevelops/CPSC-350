/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#include "Monster.h"

// default constructor
Monster::Monster() {

}

// overloaded constructor
Monster::Monster(std::string name, int screamPower) {
    this->name = name;
    this->screamPowerLevel = screamPower;
}

// deconstructor
Monster::~Monster() {
    
}

// fights opponent and returns if they won or not as a bool
bool Monster::ScreamFight(Monster opponent) {
    // if they have a higher scream power win
    if(this->GetScreamPower() > opponent.GetScreamPower()) return true;

    // otherwise lose
    return false;
}

int Monster::GetScreamPower() {
    return this->screamPowerLevel;
}

std::string Monster::GetName() { 
    return this->name;
}