#include "Matrix.h" // include the header file with the class definition
#include <iostream>
#include <cstdlib> // For rand(), atoi()
#include <ctime>   // For time()
#include <cctype>  // For isdigit()

// Constructor: Allocates memory for the matrix and sets dimensions
Matrix::Matrix(int r, int c){
    rows = r;
    cols = c;
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
}

// Destructor: Frees the allocated memory
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Method to fill the matrix with random integers
void Matrix::randomMatrix() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed for random number generation
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = std::rand() % 100; // Random integers between 0 and 99
        }
    }
}

// Method to calculate the sum of each row
void Matrix::sumRows(int* rowSums) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        rowSums[i] = sum; // Store the sum of each row in the array
    }
}

// Method to display the matrix
void Matrix::displayMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}





