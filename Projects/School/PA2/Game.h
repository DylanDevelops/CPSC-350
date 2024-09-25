/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Level.h"
#include "FileOutputProcessor.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game {
    public:
        Game();
        Game(int inputLines[], std::string outputPath);
        ~Game();

        // methods;
        void Start();
        int GetCurrentLevel();

        Direction GetRandomMoveDirection();
        int MoveMario(Direction moveDirection, int numberOfSteps,  Transform marioPos);
        void MoveOn(Transform marioTransform, int newX, int newY);

        void CollectCoin(); // for if Marios location holds "c", Mario.CollectCoin
        void CollectMushroom(); // to increase power level

        int FightGoomba(); 
        int FightKoopa();
        int FightLevelBoss();

    private:
        // methods
        void InitializeLevels();
        void PlaceMario();
        void Play();
        void LevelUp(); // ??? to move through worldArr for warp pipes and defeating level bosses 

        Level** worldArr;

        // file processor
        FileOutputProcessor* output;
        std::string outputFilePath;

        // variables
        int currentLevel;
        int levels;
        int gridDimension;
        int initialLives;
        int coinsPercentage;
        int nothingPercentage;
        int goombasPercentage;
        int koopasPercentage;
        int mushroomsPercentage;
        
        int coins;
        int powerLevel;
        int marioLives;
        int enemiesDefeatedOnSameLife;

        int totalMovesMade;
};

#endif