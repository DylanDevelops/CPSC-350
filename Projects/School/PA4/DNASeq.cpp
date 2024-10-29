/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#include "DNASeq.h"

DNASeq::DNASeq() {

}

DNASeq::DNASeq(std::string characterString) {
    // Loops through the string parameter's size
    for(int i = 0; i < characterString.length(); ++i) {
        // adds each character to the sequence
        sequence.addBack(characterString[i]);
    }
}

DNASeq::~DNASeq() {
    
}

DNASeq DNASeq::complement() {
    // Creates temp sequence
    DNASeq complementSequence;

    // loops through the sequence
    for(int i = 0; i < sequence.size(); ++i) {
        // temp letter variable
        char letter = ' ';

        // swaps the letters
        switch(sequence.get(i)) {
            case 'A':
                letter = 'T';
                break;

            case 'T':
                letter = 'A';
                break;

            case 'C':
                letter = 'G';
                break;

            case 'G':
                letter = 'C';
                break;
        }

        // adds the newly swapped letter to the complement sequence
        complementSequence.sequence.addBack(letter);
    }

    // returns the complement sequence
    return complementSequence;
}

DNASeq DNASeq::substring(int s, int e) {
    // creates temp sequence
    DNASeq tempSeq;

    // loops through sequence from s to 1 before e
    for(int i = s; i < e; ++i) {
        // adds values to temp sequence
        tempSeq.sequence.addBack(sequence.get(i));
    }

    // returns the temp sequence
    return tempSeq;
}

bool DNASeq::isGeneticPalindrome() {
    // creates the complement sequence
    DNASeq complementSequence = complement();

    for(int i = 0; i < sequence.size(); ++i) {
        // Get the equivalent char
        char equivalent = complementSequence.sequence.get(sequence.size() - 1 - i);

        // Checks if at any point in the loop the elements are not equivalent
        if(sequence.get(i) != equivalent) {
            // if they aren't then return false right there
            return false;
        }
    }

    // If it never returns false, then it is a palindrome, which returns true
    return true;
}

std::string DNASeq::toString() {
    // creates a temp result string
    std::string result = "";

    // loops through the sequence
    for(int i = 0; i < sequence.size(); ++i) {
        // adds each character to the result string
        result += sequence.get(i);
    }

    // returns the crafted string
    return result;
}