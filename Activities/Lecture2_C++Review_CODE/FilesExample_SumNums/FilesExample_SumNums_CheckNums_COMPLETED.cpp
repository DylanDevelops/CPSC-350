/*
    Program to Read Integers from numbers.txt, Sum Them, and Write the Result to sum.txt
    In the other version we read the numbers directly from the file but if a line isn't 
    a number it stopped reading from the file. Here we check if the thing in the line is a proper number
    There are other ways of doing this!
*/

#include <iostream>   // Include the iostream library for input/output operations
#include <fstream>    // Include the fstream library to handle file input/output
#include <string>     // Include the string library to use the std::string class

int main() {
    std::ifstream inFile("numbers.txt");  // Open the input file "numbers.txt"
    std::ofstream outFile("sum2.txt");     // Open the output file "sum.txt"
    std::string line;                     // Declare a string variable to store each line read from the file
    int sum = 0;                          // Initialize 'sum' to 0 to accumulate the total sum

    // Check if the input file was successfully opened
    if (inFile.is_open()) {
        // Read each line from the file
        while (getline(inFile, line)) {
            bool isNumber = true;         // Assume the line is a number
            for (char c : line) {         // Check each character in the line
                if (!isdigit(c) && c != '-' && c != '+') {
                    isNumber = false;     // If any character is not a digit or sign, it's not a valid number
                    break;
                }
            }

            if (isNumber && !line.empty()) {
                sum += std::stoi(line);   // Convert the line to an integer and add it to the sum
            } else {
                std::cout << "Skipping non-numeric line: " << line << std::endl;
                // Print a message and skip this line
            }
        }
        inFile.close();                   // Close the input file after processing all lines
    } else {
        // If the file couldn't be opened, print an error message
        std::cout << "Unable to open input file" << std::endl;
        return 1;                         // Return 1 to indicate an error occurred
    }

    // Check if the output file was successfully opened
    if (outFile.is_open()) {
        outFile << "Sum: " << sum << std::endl;  // Write the sum to the output file with a label "Sum: "
        outFile.close();                         // Close the output file after writing the result
    } else {
        // If the output file couldn't be opened, print an error message
        std::cout << "Unable to open output file" << std::endl;
        return 1;                         // Return 1 to indicate an error occurred
    }

    return 0;                             // Return 0 to indicate successful completion of the program
}
