/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#include "PalindromeFinder.h"

PalindromeFinder::PalindromeFinder() {

}

PalindromeFinder::~PalindromeFinder() {
    
}

bool PalindromeFinder::isDNAStrand(std::string sequence) {
    // loops through the sequence
    for(int i = 0; i < sequence.size(); ++i) {
        // checks if any of these chars are not A, C, T, and G then it means it is not a valid DNA sequence
        if(sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'T' && sequence[i] != 'G') {
            // if so, return false
            return false;
        }
    }

    // if it didn't return false, it means it is valid and should return true
    return true;
}

void PalindromeFinder::findPalindromeSubstrings(DNASeq& sequence, DNASeq* results[], int& count) {
    // set count to 0
    count = 0;

    // Loop through each character in the sequence
    for(int i = 0; i < sequence.toString().length(); ++i) {
        // Loop through each possible substring starting from the current character
        for(int j = i + 5; j < sequence.toString().length(); ++j) {
            // Extract the substring from the sequence
            DNASeq subSequence = sequence.substring(i, j);

            // Check if the substring is a genetic palindrome
            if(subSequence.isGeneticPalindrome()) {
                // If it is, add it to the results array and increment the count
                results[count++] = new DNASeq(subSequence);
            }
        }
    }
}