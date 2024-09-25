/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "Level.h"

Level::Level() {
    gameGrid = nullptr;
    gridSize = 0;
    emptySpaces = 0;
}

Level::Level(int N, int probCoin, int probNothing, int probGoomba, int probKoopa, int probMushroom) {
    gridSize = N;
    emptySpaces = 0;

    // delete this
    probOfCoin = probCoin;
    probOfNothing = probNothing;
    probOfGoomba = probGoomba;
    probofKoopa = probKoopa;
    probOfMushroom = probMushroom;

    // create 2D array of characters
    gameGrid = new GameObject*[gridSize];
    for (int i = 0; i < gridSize; ++i) {
        gameGrid[i] = new GameObject[gridSize];
    }
}

Level::~Level() {
    for (int i = 0; i < gridSize; ++i) {
        delete[] gameGrid[i];
    }
    delete[] gameGrid;
}

void Level::InitializeGrid(int levelIndex, int numOfLevels) {
    emptySpaces = gridSize * gridSize;

    // place H (mario), b (level boss), and w (warp pipe)
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            // if (H, b, or w), skip, otherwise randomly populate with one of the others
            gameGrid[row][col] = RandomlyPopulate();
            gameGrid[row][col].SetTransform(row, col);
            if(gameGrid[row][col].GetChar() != 'x') {
                --emptySpaces;
            }
        }
    }

    // Placing warp pipe
    if(levelIndex < (numOfLevels - 1) && emptySpaces > 0) {
        bool warpPipePlaced = false;
        while(!warpPipePlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            if(gameGrid[row][col].GetChar() == 'x') {
                // checks if it is just a plain GameObject meaning it is empty
                gameGrid[row][col] = WarpPipe();
                gameGrid[row][col].SetTransform(row, col);
                --emptySpaces;
                warpPipePlaced = true;
            }
        }
    } else if(levelIndex < (numOfLevels - 1)) {
        bool warpPipePlaced = false;
        while(!warpPipePlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            
            gameGrid[row][col] = WarpPipe();
            gameGrid[row][col].SetTransform(row, col);
            warpPipePlaced = true;
        }
    }

    // placing level boss
    if(emptySpaces > 0) {
        bool levelBossPlaced = false;
        while(!levelBossPlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            if(gameGrid[row][col].GetChar() == 'x') {
                // checks if it is just a plain GameObject meaning it is empty
                gameGrid[row][col] = LevelBoss();
                gameGrid[row][col].SetTransform(row, col);
                --emptySpaces;
                levelBossPlaced = true;
            }
        }
    } else {
        bool levelBossPlaced = false;
        while(!levelBossPlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            if(gameGrid[row][col].GetChar() != 'w') {
                // checks if it is a warp pipe meaning it should not spawn there
                gameGrid[row][col] = LevelBoss();
                gameGrid[row][col].SetTransform(row, col);
                levelBossPlaced = true;
            }
        }
    }
}

void Level::SpawnMario(int lives) {
    if(emptySpaces > 0) {
        bool marioPlaced = false;
        while(!marioPlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            if(gameGrid[row][col].GetChar() == 'x') {
                // checks if it is just a plain GameObject meaning it is empty
                gameGrid[row][col] = Mario(lives);
                gameGrid[row][col].SetTransform(row, col);
                --emptySpaces;
                marioPlaced = true;
            }
        }
    } else {
        bool marioPlaced = false;
        while(!marioPlaced) {
            int row = std::rand() % gridSize; // gets a random x position
            int col = std::rand() % gridSize; // gets a random y position
            if((gameGrid[row][col].GetChar() != 'w') && (gameGrid[row][col].GetChar() != 'b')) {
                // checks if it is a warp pipe or level boss meaning it should not spawn there
                gameGrid[row][col] = Mario(lives);
                gameGrid[row][col].SetTransform(row, col);
                --emptySpaces;
                marioPlaced = true;
            }
        }
    }
}

GameObject Level::GetMario() {
    for(int row = 0; row < gridSize; ++row) {
        for(int col = 0; col < gridSize; ++col) {
            if(gameGrid[row][col].GetChar() == 'H') {
                return gameGrid[row][col];
            }
        }
    }
}

GameObject Level::RandomlyPopulate() {
    int randNum = std::rand() % 100; // random number between 0 and 99
    if (randNum < probOfCoin) {
        return Coin(); // coin assigned
    } else if (randNum < (probOfCoin + probOfGoomba)) {
        return Goomba(); // goomba assigned
    } else if (randNum < (probOfCoin + probOfGoomba + probOfMushroom)) {
        return Mushroom(); // mushroom assigned
    } else if (randNum < (probOfCoin + probOfGoomba + probOfMushroom + probOfNothing)) {
        return GameObject(); // nothing assigned
    } else { //  (randNum < 100)
        return KoopaTroopa(); // koopa assigned
    }
}

std::string Level::DisplayGrid() {
    std::string result = "";

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            //std::cout << gameGrid[row][col].GetChar() << " ";
            result += gameGrid[row][col].GetChar();
            result += " ";
        }
        //std::cout << std::endl;
        result += "\n";
    }
    
    return result;
}