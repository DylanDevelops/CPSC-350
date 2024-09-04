#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    You need to create a C++ program with three main parts. First, write a sumRows() 
    function that takes a matrix of integers (as a pointer to an array of pointers)
     and a one-dimensional array (as a pointer). This function will calculate the sum of each row 
     in the matrix and store these sums in the one-dimensional array. 
     
     Next, create a randomMatrix() function that accepts the number of rows and columns as input, 
     then fills a dynamically allocated matrix with random integers. 
     
     Finally, in the main() function, prompt the user to input the dimensions of the matrix, 
     allocate memory for it, and use randomMatrix() to fill it with random values. After displaying the matrix, 
     call sumRows() to compute and display the sum of each row. 
     
     Remember tofree the allocated memory before the program exits to avoid memory leaks.

     Edit the previous program to get the dimensions of the matrix from command line arguments. 
     If there are no command line arguments given or they are invalid, then get user input 
     for the dimensions. 
*/


// Function to fill an array with the sum of each row of the matrix
void sumRows(int** matrix, int* rowSums, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        rowSums[i] = sum;  
    }
}

// Function to create a matrix with random integers
void randomMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = std::rand() % 100; // Random integers between 0 and 99
        }
    }
}

// ADDITION:
// Helper function to check if a string is a positive integer
bool isPositiveInteger(const char* str) {
    while (*str) {
        if (!std::isdigit(*str)) return false;
        ++str;
    }
    return true;
}

// MODIFY: add the parameters to be able to take in command line args, just like String[] args in Java 
int main(int argc, char* argv[]) { // int argc = number of command line args given
                                   // char* argv[] essentially an array of strings (char arrays) holding the command line args given 
                                   // argv[0] is always the name of the program

    std::srand(static_cast<unsigned>(std::time(0))); // Seed for random number generation, std::time(0)) to make sure we get different numbers whenever we run the program

    int rows, cols;

    // Check if command-line arguments are provided and valid
    if (argc >= 3 && isPositiveInteger(argv[1]) && isPositiveInteger(argv[2])) {
        rows = std::atoi(argv[1]);  // std::atoi() -> converts a C-style string (a character array or a pointer to a character) into an integer 
        cols = std::atoi(argv[2]);
    } else {
        // Get matrix dimensions from user
        std::cout << "Enter the number of rows: ";
        std::cin >> rows;
        std::cout << "Enter the number of columns: ";
        std::cin >> cols;
    }

    // Dynamically allocate memory for the matrix
    int** matrix = new int*[rows]; // pointer to an array of pointers, aka a 2D array or matrix 
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]; // got to initialize each 'inner' array 
    }

    // Dynamically allocate memory for the row sums array
    int* rowSums = new int[rows];

    // initialize the matrix with random numbers
    randomMatrix(matrix, rows, cols);

    // Display the generated matrix
    std::cout << "\nMatrix of random numbers:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Calculate the sum of each row
    sumRows(matrix, rowSums, rows, cols);

    // Display the sum of each row
    std::cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Row " << i + 1 << ": " << rowSums[i] << std::endl;
    }

    // Free the allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];  // delete each 'inner' array 
    }
    delete[] matrix;
    delete[] rowSums;

    return 0;
}
