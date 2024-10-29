#include "FileProcessor.h"
/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#include "FileProcessor.h"

FileProcessor::FileProcessor() {

}

FileProcessor::FileProcessor(std::string inputFile) {
    fileName = inputFile;
}

FileProcessor::~FileProcessor() {

}

void FileProcessor::processFile() {
    // opens the file
    std::ifstream inputFile;
    inputFile.open(fileName);

    // Check if the file is open
    if(!inputFile.is_open()) {
        std::cerr << "[ERROR] - There was an issue opening the input file. Please try again!" << std::endl;
        return;
    }

    // declares temp variables for handling
    int lineCount = 0;
    std::string line = "";

    // Count the number of lines until "END" is encountered
    while(getline(inputFile, line)) {
        if(line == "END") {
            break;
        }
        ++lineCount;
    }

    // opens and closes the file to start again
    inputFile.close();
    inputFile.open(fileName);

    std::string outputContent = "";

    // Process each line in the file
    while(getline(inputFile, line)) {
        if(line == "END") {
            break;
        }

        // Check if the line is a valid DNA strand
        if(!PalindromeFinder::isDNAStrand(line)) {
            outputContent += line + " - INVALID\n";
            continue;
        }

        DNASeq dnaSequence(line);
        // Check if the DNA sequence is a genetic palindrome
        if (dnaSequence.isGeneticPalindrome()) {
            outputContent += line + " - Genetic Palindrome\n";
        } else {
            outputContent += line + " - Not a Genetic Palindrome\n";
        }

        DNASeq* palindromeSubstrings[lineCount];
        int count = 0;
        // Find all substrings in the DNA sequence
        PalindromeFinder::findPalindromeSubstrings(dnaSequence, palindromeSubstrings, count);

        // adds each substring to the string that will be outputted
        for(int i = 0; i < count; ++i) {
            outputContent += "\tSubstring " + palindromeSubstrings[i]->toString() + " - Genetic Palindrome\n";
            delete palindromeSubstrings[i];
        }
    }

    inputFile.close();

    // Print the output content
    std::cout << outputContent << std::endl;
}