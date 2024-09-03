#include <iostream>
#include "FileProcessor.h"

int main(int argc, char* argv[]) {
    // Checks if there are the correct number of arguments
    if(argc != 3) {
        std::cerr << "[INCORRECT USAGE] Please run program as follows: " << argv[0] << " [INPUT FILE NAME] [OUTPUT FILE NAME]" << std::endl;
        return 1;
    }

    // Processes the file using the file processor while passing in the input file name and output file name as arguments
    FileProcessor fileProcessor;
    fileProcessor.processFile(argv[1], argv[2]);

    // Returns a 0 because it successfully ran
    return 0;
}