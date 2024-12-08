/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA6: Spanning the Gamut
*/

#include <iostream>
#include "FileProcessor.h"

int main(int argc, char* argv[]) {
    // Checks if no input file has been passed in
    if(argc != 2) {
        std::cerr << "[ERROR] - You ran the program incorrectly. Please try again with the following usage: '" << argv[0] << " INPUT_FILE.txt'" << std::endl;
        return 1;
    }

    // Creates a file processor to use
    FileProcessor* fileProcessor = new FileProcessor(argv[1]);
    fileProcessor->ProcessInputFile();

    // Deletes the file processor
    delete fileProcessor;

    // Ends main method
    return 0;
}