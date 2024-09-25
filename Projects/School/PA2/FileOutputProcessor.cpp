/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "FileOutputProcessor.h"

FileOutputProcessor::FileOutputProcessor() {
    
}

FileOutputProcessor::FileOutputProcessor(std::string path) {
    this->outPutFilePath = path;
    this->PrepareFile();
}

FileOutputProcessor::~FileOutputProcessor() {

}

void FileOutputProcessor::PrepareFile() {
    std::ofstream outputFile;
    outputFile.open(outPutFilePath);

    if(outputFile.is_open()) {
        outputFile << "MARIO GAME STARTS HERE:" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "OUTPUT [ERROR] There was an issue opening the output file. Please try again!" << std::endl;
    }

}

void FileOutputProcessor::Print(std::string text) {
    std::ofstream outputFile;
    outputFile.open(outPutFilePath, std::ios::app);

    if(outputFile.is_open()) {
        // Outputs to the output file
        outputFile << text;

        // Closes the output file
        outputFile.close();
    } else {
        // Error handling for output file
        std::cerr << "OUTPUT [ERROR] There was an issue opening the output file. Please try again!" << std::endl;
    }
}