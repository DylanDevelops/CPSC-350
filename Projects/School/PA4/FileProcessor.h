/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <fstream>
#include "DNASeq.h"
#include "PalindromeFinder.h"

class FileProcessor {
    public:
        // constructors and destructors
        FileProcessor();
        FileProcessor(std::string fileName);
        ~FileProcessor();

        // methods
        void processFile();

    private:
        std::string fileName;
};

#endif