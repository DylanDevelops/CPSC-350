/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef LEVEL_H
#define LEVEL_H

#include <cstdlib>
#include <iostream>
#include <typeinfo>

#include "GameObject.h"
#include "Coin.h"
#include "Goomba.h"
#include "Mushroom.h"
#include "KoopaTroopa.h"
#include "WarpPipe.h"
#include "LevelBoss.h"
#include "Mario.h"

class Level {
    public:
        Level();
        Level(int N, int probCoin, int probNothing, int probGoomba, int probKoopa, int probMushroom);
        ~Level();
        GameObject RandomlyPopulate();
        std::string DisplayGrid();
        void SpawnMario(int lives);
        GameObject GetMario();
        void InitializeGrid(int levelIndex, int numOfLevels);
        GameObject** gameGrid;

    private:
        int gridSize;
        int probOfCoin;
        int probOfNothing;
        int probOfGoomba;
        int probofKoopa;
        int probOfMushroom;
        int emptySpaces;

};

#endif