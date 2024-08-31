
/*
Write a program that reads integers from a file called numbers.txt, sums them up, and writes the result to a file called sum.txt.
*/
#include <iostream>   // Include the iostream library for input/output operations
#include <fstream>    // Include the fstream library to handle file input/output

int main() {
    std::ifstream inFile("numbers.txt");  // Create an ifstream object named inFile to read from the file "numbers.txt", make sure this exists
    std::ofstream outFile("sum.txt");     // Create an ofstream object named outFile to write to the file "sum.txt"
    int number, sum = 0;                  // Declare an integer variable number to store each integer read from the file
                                          // and initialize sum to 0 to accumulate the total sum
    // Check if the file was successfully opened
    if (inFile.is_open()) {
        
        // Read integers from the file and add them to sum
        while (inFile >> number) {        // Use the extraction operator >> to read and save an integer from inFile into number
            sum += number;                // Add the read integer to the sum
        }
        
        // you can read the numbers directly from the file but if a line isn't a number it will stop reading from the file. 
            // Checkout edited file to get a more robust version 

        inFile.close();                   // Close the input file after reading all the integers
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
