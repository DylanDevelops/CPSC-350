/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#ifndef DNA_SEQ_H
#define DNA_SEQ_H

#include <iostream>
#include "DblList.h"

class DNASeq {
    public:
        // constructors
        DNASeq();
        DNASeq(std::string characterString);

        // destructor
        ~DNASeq();

        // methods
        DNASeq complement();
        DNASeq substring(int s, int e);
        bool isGeneticPalindrome();
        std::string toString();

    private:
        DblList<char> sequence;
};

#endif