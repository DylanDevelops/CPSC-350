/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "FileInputProcessor.h"
#include "Game.h"
#include "Mario.h"

FileInputProcessor::FileInputProcessor() {
    readValues = nullptr;
    numValues = 8;
}

FileInputProcessor::~FileInputProcessor() {
    delete[] readValues;
}

void FileInputProcessor::ReadFile(std::string inputPath) {
    std::ifstream inputFile;
    inputFile.open(inputPath);

    std::string line = "";

    int lineValue = 0;

    if(inputFile.is_open()) {
        readValues = new int[numValues]; // Allocates memory for readValues the correct way. Different than how we did it previously 😭
        while(getline(inputFile, line) && lineValue < numValues) {
            readValues[lineValue] = std::stoi(line);
            lineValue++;
        }
        inputFile.close();
    } else {
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }
}