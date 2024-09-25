/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef FILE_INPUT_PROCESSOR_H
#define FILE_INPUT_PROCESSOR_H

#include <iostream>
#include <fstream>

class FileInputProcessor {
    public:
        FileInputProcessor();
        ~FileInputProcessor();
        
        // method
        void ReadFile(std::string inputFile);

        // variables
        int* readValues;

    private:
        int numValues;
};

#endif