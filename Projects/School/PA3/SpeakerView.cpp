/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA3: Do You See What I See?
*/

#include <fstream>
#include "SpeakerView.h"

SpeakerView::SpeakerView(std::string inputFile) {
    inputPath = inputFile;
    numRows = 0;
    numCols = 0;
}

SpeakerView::~SpeakerView() {

}

void SpeakerView::Process() {
    DetermineDimensions();
}

void SpeakerView::DetermineDimensions() {
    std::ifstream inputFile;
    inputFile.open(inputPath);
    
    std::string line = "";
    bool inSelection = false;
    bool foundCols = false;

    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            if(line == "BEGIN") {
                inSelection = true;
                continue;
            }

            if(line == "END") {
                break;
            }

            if(inSelection && !line.empty()) {
                std::cout << line << std::endl;
                numRows++;
                if(!foundCols) {
                    for(char c : line) {
                        if(c == ' ') {
                            numCols++;
                        }
                    }
                    foundCols = true;
                }
            }
        }
        inputFile.close();

        std::cout << numCols << " x " << numRows << std::endl;
    } else {
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }
    
    // std::ifstream inputFile;
    // inputFile.open(inputPath);

    // std::string line = "";

    // int lineValue = 0;

    // if(inputFile.is_open()) {
    //     readValues = new int[numValues]; // Allocates memory for readValues the correct way. Different than how we did it previously 😭
    //     while(getline(inputFile, line) && lineValue < numValues) {
    //         readValues[lineValue] = std::stoi(line);
    //         lineValue++;
    //     }
    //     inputFile.close();
    // } else {
    //     std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    // }
}

void SpeakerView::DisplayResults() {

}