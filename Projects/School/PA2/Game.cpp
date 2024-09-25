/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "Game.h"

Game::Game() {
    
}

Game::Game(int inputLines[], std::string outputPath)
{
    levels = inputLines[0];
    gridDimension = inputLines[1];
    initialLives = inputLines[2];
    coinsPercentage = inputLines[3];
    nothingPercentage = inputLines[4];
    goombasPercentage = inputLines[5];
    koopasPercentage = inputLines[6];
    mushroomsPercentage = inputLines[7];
    currentLevel = 0;
    enemiesDefeatedOnSameLife = 0;
    powerLevel = 0;
    coins = 0;
    totalMovesMade = 0;

    outputFilePath = outputPath;
    output = new FileOutputProcessor(outputFilePath);

    worldArr = new Level*[levels];
    for(int i = 0; i < levels; ++i) {
        worldArr[i] = new Level(gridDimension, coinsPercentage, nothingPercentage, goombasPercentage, koopasPercentage, mushroomsPercentage);
    }
}

Game::~Game() {
    for(int i = 0; i < levels; ++i) {
        delete worldArr[i]; // Deletes each Level object
    }
    delete[] worldArr; // Deletes the array of pointers

    // deletes the file processor
    delete output;
}

void Game::Start() {
    InitializeLevels();

    output->Print("\n" + std::to_string(levels) + " levels have been generated: \n\n");
    //std::cout << "\n" << levels << " levels have been generated:\n" << std::endl;

    for(int i = 0; i < levels; ++i) {
        output->Print("Level #" + std::to_string(i + 1) + "\n");
        //std::cout << "Level #" << (i + 1) << std::endl;

        output->Print(worldArr[i]->DisplayGrid());
        //worldArr[i]->DisplayGrid();
        
        output->Print("------------------\n");
        //std::cout << "------------------" << std::endl;
    }

    //std::cout << "\n" << "Placing Mario in first level:\n" << std::endl;
    output->Print("\nPlacing Mario in first level:\n");

    PlaceMario();

    output->Print(worldArr[currentLevel]->DisplayGrid());
    //worldArr[currentLevel]->DisplayGrid();

    Play();
}

void Game::InitializeLevels() {
    for(int i = 0; i < levels; ++i) {
        worldArr[i]->InitializeGrid(i, levels);
    }
    currentLevel = 0;
}

void Game::PlaceMario() {
    worldArr[0]->SpawnMario(initialLives);
    marioLives = initialLives;
}

void Game::Play() {
    // main gameplay loop
    bool isAlive = true;
    bool wonGame = false;
    for(int i = 0; i < levels; i++) {
        bool moveToNextLevel = false;
        // loops through every level
        while(isAlive && !wonGame && !moveToNextLevel) {
            totalMovesMade++;
            output->Print("\nLevel #" + std::to_string(currentLevel + 1) + "\n\n");

            Transform currentMarioPos = worldArr[i]->GetMario().GetTransform();
            output->Print("Mario is at position: " + currentMarioPos.ToString() + "\n");

            // mario's current power level before interacting with the position
            output->Print("Mario is at power level: " + std::to_string(powerLevel) + "\n");

            // move mario up for testing purposes
            Direction randomDirection = GetRandomMoveDirection();
            int moveResult = MoveMario(randomDirection, 1, currentMarioPos);

            switch(moveResult) {
                case 0:
                    // alive
                    //output->Print("You survived\n"); // TODO: these are not the right wording?
                    //std::cout << "You survived" << std::endl;
                    break;
                
                case 1:                    
                    //std::cout << "You are dead!" << std::endl;
                    isAlive = false;
                    // died
                    break;
                
                case 2:
                    // teleport to next level
                    output->Print("Mario warped to the next level.\n");
                    //std::cout << "WARPING TO NEXT LEVEL" << std::endl;
                    LevelUp(); // TODO: FINISH THIS
                    worldArr[currentLevel]->SpawnMario(marioLives);
                    moveToNextLevel = true;
                    break;

                case 3:
                    //std::cout << "YOU WON THE GAME" << std::endl;
                    wonGame = true;
                    break;
            }
            output->Print("Mario has " + std::to_string(marioLives) + " lives left.\n"); // TODO: i don't think mariolives gets assigned to something we can access here
            output->Print("Mario has " + std::to_string(coins) + " coins.\n");
            
            if(!wonGame) {
                output->Print(worldArr[currentLevel]->DisplayGrid());
                worldArr[currentLevel]->DisplayGrid();
                output->Print("-----------------------\n");
            }

            if(marioLives <= 0) {
                isAlive = false;
            }
        }

        if(!isAlive || wonGame) {
            break;
        }
    }
    if (!isAlive) {
        output->Print("WE LOST THE GAME!\n");
    }
    if (wonGame) {
        output->Print("WE WON THE GAME!\n");
    }
    output->Print("It took " + std::to_string(totalMovesMade) + " moves.");
    //std::cout << "Made it out of the game loop!" << std::endl;
}

void Game::LevelUp() {
    currentLevel++;
}

int Game::GetCurrentLevel() {
    return currentLevel;
}

Direction Game::GetRandomMoveDirection() {
    int randomValue = std::rand() % 4; // 4 directions to choose from

    switch(randomValue) {
        case 0:
            output->Print("Mario will move UP\n");
            //std::cout << "Chose UP" << std::endl;
            return Direction::UP;

        case 1:
            output->Print("Mario will move DOWN\n");
            //std::cout << "Chose DOWN" << std::endl;
            return Direction::DOWN;

        case 2:
            output->Print("Mario will move LEFT\n");
            //std::cout << "Chose LEFT" << std::endl;
            return Direction::LEFT;

        case 3:
            output->Print("Mario will move RIGHT\n");
            //std::cout << "Chose RIGHT" << std::endl;
            return Direction::RIGHT;
    }
}

int Game::MoveMario(Direction moveDirection, int numberOfSteps, Transform marioTransform) {
    int newX = marioTransform.GetX();
    int newY = marioTransform.GetY();

    switch (moveDirection) {
        case UP:
            // row - 1, column stays same
            newX -= numberOfSteps;
            if(newX < 0) {
                newX = gridDimension - 1;
            }
            break;

        case DOWN:
            // row + 1, column stays same
            newX += numberOfSteps;
            if(newX >= gridDimension) {
                newX = 0;
            }
            break;

        case LEFT:
            // row stays same, column - 1
            newY -= numberOfSteps;
            if(newY < 0) {
                newY = gridDimension - 1;
            }
            break;

        case RIGHT:
            // row stays same, column + 1
            newY += numberOfSteps;
            if(newY >= gridDimension) {
                newY = 0;
            }
            break;
    }

    // Checks what exists at the chosen coords
    switch(worldArr[currentLevel]->gameGrid[newX][newY].GetChar()) {
        case 'x':
            // hit nothing
            output->Print("Mario visited an empty space.\n");
            MoveOn(marioTransform, newX, newY);
            return 0;
        
        case 'c':
            // hit a coin
            CollectCoin();
            MoveOn(marioTransform, newX, newY);
            return 0;

        case 'm':
            // hit a mushroom
            CollectMushroom();
            MoveOn(marioTransform, newX, newY);
            return 0;

        case 'g': {
            // hit a koopa
            int goombaResult = FightGoomba();

            if(goombaResult == 0) {
                // defeated goomba
                MoveOn(marioTransform, newX, newY);
                return 0;
            } else if(goombaResult == 1) {
                // died to goomba
                return 1;
            } else {
                // lost to goomba but still has lives
                return 0;
            }
        }
            
        case 'k': {
            // hit a koopa
            int koopaResult = FightKoopa();
            
            if(koopaResult == 0) {
                // defeated koopa
                MoveOn(marioTransform, newX, newY);
                return 0;
            } else if(koopaResult == 1) {
                // died to koopa
                return 1;
            } else {
                // lost to koopa but still has lives
                return 0;
            }
        }

        case 'b': {
            // hit a level boss
            int levelBossFightResult = FightLevelBoss();
            if(levelBossFightResult == 0) {
                // defeated boss and warp to next level
                if(currentLevel == (levels - 1)) {
                    // this is the last level and you won!
                    return 3;
                } else {
                    return 2;
                }
            } else {
                // he lost to the boss
                return 1;
            }
        }   

        case 'w':
            // hit a warp pipe
            return 2;
    }

    return 0;
}

void Game::MoveOn(Transform mTransform, int x, int y) {
    worldArr[currentLevel]->gameGrid[mTransform.GetX()][mTransform.GetY()] = GameObject();
    worldArr[currentLevel]->gameGrid[x][y] = Mario(marioLives);
    worldArr[currentLevel]->gameGrid[x][y].SetTransform(x, y);
}

void Game::CollectCoin() {
    coins++;
    output->Print("Mario collected a coin.\n");
    if (coins == 20) {
        marioLives++;
        coins = 0;
    }
}

void Game::CollectMushroom() {
    output->Print("Mario ate a mushroom.\n");
    if (powerLevel < 2) {
        powerLevel++;
    }
}

int Game::FightGoomba() {
    int randomValue = std::rand() % 100;

    if(randomValue < 80) {
        output->Print("Mario fought a goomba and won.\n");
        enemiesDefeatedOnSameLife++;

        // checks if another life should be added
        if(enemiesDefeatedOnSameLife >= 7) {
            marioLives++;
            enemiesDefeatedOnSameLife = 0;
        }

        return 0;
    } else {
        output->Print("Mario fought a goomba and lost. \n");

        if(powerLevel > 0) {
            powerLevel--;
        } else {
            marioLives--;
            if(marioLives > 0) {
                powerLevel = 0;
                enemiesDefeatedOnSameLife = 0;
                //std::cout << "Mario lost a life but continues with PL0." << std::endl;
                return 2;
            } else {
                //std::cout << "Mario has no more lives. Game over!" << std::endl;
                return 1;
            }
        }

        return 0;
    }
}

int Game::FightKoopa() {
    int randomValue = std::rand() % 100;

    if(randomValue < 65) {
        output->Print("Mario fought a koopa and won. \n");
        enemiesDefeatedOnSameLife++;

        if(enemiesDefeatedOnSameLife >= 7) {
            marioLives++;
            enemiesDefeatedOnSameLife = 0;
            //std::cout << "Mario defeated 7 enemies without losing and earned an extra life." << std::endl;
        }

        return 0;
    } else {
        output->Print("Mario fought a koopa and lost. \n");
        //std::cout << "Mario lost to the Koopa!" << std::endl;
        if(powerLevel > 0) {
            powerLevel--;
        } else {
            marioLives--;
            if(marioLives > 0) {
                powerLevel = 0;
                enemiesDefeatedOnSameLife = 0;
                //std::cout << "Mario lost a life but continues with PL0." << std::endl;
                return 2;
            } else {
                //std::cout << "Mario has no more lives. Game over!" << std::endl;
                return 1;
            }
        }

        return 0;
    }
}

int Game::FightLevelBoss() {
    while (true) {
        int randomValue = std::rand() % 100; // Generate a random number between 0 and 99

        if (randomValue < 50) {
            output->Print("Mario fought the level boss and won!\n");
            //std::cout << "Mario defeated the Level Boss!" << std::endl;
            return 0;
        } else {
            output->Print("Mario fought the level boss and lost.\n");
            //std::cout << "Mario lost to the Level Boss!" << std::endl;
            if (powerLevel >= 2) {
                powerLevel -= 2;
                //std::cout << "Mario's power level decreased by 2. Current power level: " << powerLevel << std::endl;
            } else { // mario's power level is 0 or 1
                marioLives--;
                if (marioLives > 0) {
                    powerLevel = 0;
                    //std::cout << "Mario lost a life but continues with PL0. Lives left: " << marioLives << std::endl;
                } else {
                    //std::cout << "Mario has no more lives. Game over!" << std::endl;
                    return 1;
                }
            }
        }
    }
}