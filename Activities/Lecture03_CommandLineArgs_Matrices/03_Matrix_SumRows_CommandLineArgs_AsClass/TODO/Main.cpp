#include "Matrix.h"
#include <iostream>

// Helper function to check if a string is a positive integer
bool isPositiveInteger(char* str) {
    int i = 0;

    // Loop through each character in the string
    while (str[i] != '\0') { // '\0' is the null terminator that marks the end of a C-string
        if (!std::isdigit(str[i])) { // Check if the current character is not a digit
            return false; // If any character is not a digit, return false
        }
        i++; // Move to the next character
    }

    return true; // If all characters are digits, return true
}

int main(int argc, char* argv[]) {
    int rows, cols;

    // Check if command-line arguments are provided and valid
    if (argc >= 3 && isPositiveInteger(argv[1]) && isPositiveInteger(argv[2])) {
        rows = std::atoi(argv[1]);
        cols = std::atoi(argv[2]);
    } else {
        // Get matrix dimensions from user
        std::cout << "Enter the number of rows: ";
        std::cin >> rows;
        std::cout << "Enter the number of columns: ";
        std::cin >> cols;
    }

    // Create a Matrix object
    Matrix matrix(rows, cols);

    // Fill the matrix with random values
    matrix.randomMatrix();

    // Display the generated matrix
    std::cout << "\nMatrix of random numbers:\n";
    matrix.displayMatrix();

    // Allocate memory for the row sums array
    int* rowSums = new int[rows];

    // Calculate and display the sum of each row
    matrix.sumRows(rowSums);
    std::cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Row " << i + 1 << ": " << rowSums[i] << std::endl;
    }

    // Free the row sums array
    delete[] rowSums;

    return 0;
}
