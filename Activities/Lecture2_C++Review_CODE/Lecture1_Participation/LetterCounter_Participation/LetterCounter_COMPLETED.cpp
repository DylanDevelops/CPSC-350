/*
    Write a program that reads words from a file called words.txt, 
    calculates the length of each word, and writes each word along with its length 
    to a file called word_lengths.txt. 
    Each line in the output file should contain a word followed by its length. 
    E.g,
    I: 1
    Love: 4
    Chapman: 7
    And: 3
    Data: 4
    Structures: 10

    MUST HAVE A FILE CALLED words.txt with the format:
    I 
    Love
    Chapman   
    And
    Data
    Structures
*/

#include <iostream>   // Include the iostream library for input/output operations
#include <fstream>    // Include the fstream library to handle file input/output
#include <string>     // Include the string library to use the std::string class

int main() {
    std::ifstream inFile("words.txt");       // Open the input file "words.txt"
    std::ofstream outFile("word_lengths.txt"); // Open the output file "word_lengths.txt"
    std::string word;                        // Declare a string variable to store each word

    // Check if the input file was successfully opened
    if (inFile.is_open()) {
        // Read each word from the file
        while (inFile >> word) {             // Extract each word from the input file
            int length = word.length();      // Calculate the length of the word
            outFile << word << ": " << length << std::endl; // Write the word and its length to the output file
        }
        inFile.close();                      // Close the input file after processing all words
    } else {
        // If the file couldn't be opened, print an error message
        std::cout << "Unable to open input file" << std::endl;
        return 1;                            // Return 1 to indicate an error occurred
    }

    // Check if the output file was successfully opened
    if (outFile.is_open()) {
        outFile.close();                     // Close the output file after writing all words and their lengths
    } else {
        // If the output file couldn't be opened, print an error message
        std::cout << "Unable to open output file" << std::endl;
        return 1;                            // Return 1 to indicate an error occurred
    }

    return 0;                                // Return 0 to indicate successful completion of the program
}
