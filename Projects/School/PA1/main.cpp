#include <iostream>
#include "FileProcessor.h"

int main(int argc, char* argv[]) {
    // Checks if there are the correct number of arguments
    if(argc != 3) {
        std::cerr << "[INCORRECT USAGE] Please run program as follows: " << argv[0] << " [INPUT FILE NAME] [OUTPUT FILE NAME]" << std::endl;
        return 1;
    }

    // Stores the arguments to two variables
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    // Processes the file using the file processor
    FileProcessor fileProcessor;
    fileProcessor.processFile(inputFile, outputFile);

    return 0;
}