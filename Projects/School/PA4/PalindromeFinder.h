/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include "DNASeq.h"

class PalindromeFinder {
    public:
        // constructors and destructors
        PalindromeFinder();
        ~PalindromeFinder();

        // methods
        static bool isDNAStrand(std::string sequence);
        static void findPalindromeSubstrings(DNASeq& sequence, DNASeq* results[], int& count);
};

#endif