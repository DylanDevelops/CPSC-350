/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Monster {
    public:
        Monster();
        Monster(std::string name, int screamPower);
        ~Monster();
        bool ScreamFight(Monster opponent);
        int GetScreamPower();
        std::string GetName();

    private:
        std::string name;
        int screamPowerLevel;
};

#endif