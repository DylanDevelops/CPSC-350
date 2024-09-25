/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef MARIO_H
#define MARIO_H

#include "Character.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "LevelBoss.h"

class Mario : public Character {
    public:
        Mario();
        Mario(int inputLives);
        ~Mario();

    private:
        int lives;
        int powerLevel; // can be 0, 1, or 2
};

#endif