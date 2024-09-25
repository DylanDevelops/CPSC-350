/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef FILE_OUTPUT_PROCESSOR_H
#define FILE_OUTPUT_PROCESSOR_H

#include <iostream>
#include <fstream>

class FileOutputProcessor {
    public:
        FileOutputProcessor();
        FileOutputProcessor(std::string path);
        ~FileOutputProcessor();
        
        // methods
        void Print(std::string text);

        // variables
        int* readValues;

    private:
        // methods
        void PrepareFile();

        std::string outPutFilePath;
};

#endif