#include <iostream>    // For standard I/O operations (std::cout, std::cin)
#include <fstream>     // For file I/O operations (std::ifstream)
#include <cstdlib>     // For standard library functions (exit)
#include <string>      // For using the std::string class

/*
    Function to read the matrix from a file
    Parameters:
    - filename: The name of the file containing the matrix (passed by value as std::string)
    - m: Reference to an integer to store the number of rows of the matrix
    - n: Reference to an integer to store the number of columns of the matrix
    Returns:
    - A pointer to a dynamically allocated 2D array (matrix) filled with the values from the file
*/
int** matrixFromFile(std::string filename, int& m, int& n) {
    // Create an input file stream to read from the specified file
    std::ifstream file(filename);
    
    // Check if the file was successfully opened
    if (!file.is_open()) {
        // If the file could not be opened, print an error message and exit the program
        std::cout << "Unable to open file\n";
        exit(EXIT_FAILURE); // EXIT_FAILURE is a macro that indicates unsuccessful termination
    } 

    // Read the dimensions of the matrix from the first two lines of the file
    file >> m >> n; // m stores the number of rows, n stores the number of columns
    
    // Validate that m and n are positive integers
    if (m <= 0 || n <= 0) {
        // If either m or n is invalid (non-positive), print an error message and exit
        std::cout << "Invalid matrix dimensions: " << m << "x" << n << std::endl;
        exit(EXIT_FAILURE); // Exit with an error status
    }

    // Dynamically allocate memory for a 2D array (matrix) with m rows
    int** matrix = new int*[m];
    
    // For each row, allocate memory for an array of n integers (columns)
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }

    // Populate the matrix with values from the file
    bool notEnoughData = false; // Flag to check if the file has enough data
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(file >> matrix[i][j])) {  // If we can't read a number, set flag
                notEnoughData = true;
                matrix[i][j] = 0; // Fill remaining cells with a default value (0)
            }
        }
    }

    // Check if there was not enough data in the file
    if (notEnoughData) {
        std::cerr << "Warning: The file did not contain enough data to fully populate the matrix. "
                     "Remaining elements have been filled with 0." << std::endl;
    }

    // Close the file after reading all the data
    file.close();

    // Return the pointer to the dynamically allocated matrix
    return matrix;
}


/*
    Function to calculate the sum of the diagonal elements of a square matrix
    Parameters:
    - matrix: A pointer to a 2D array (matrix) containing the matrix data
    - m: The number of rows (and columns) in the matrix (must be square, so m == n)
    Returns:
    - An integer representing the sum of the diagonal elements of the matrix
*/
int matrixDiagonal(int** matrix, int m) {
    int diagonalSum = 0; // Initialize the sum of diagonal elements to 0
    
    // Loop through the diagonal elements of the matrix
    for (int i = 0; i < m; ++i) {
        diagonalSum += matrix[i][i]; // Add the diagonal element to the sum
    }
    
    // Return the calculated sum of diagonal elements
    return diagonalSum;
}



/*
    Main function
    Parameters:
    - argc: The number of command-line arguments
    - argv: An array of C-strings representing the command-line arguments
*/
int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc < 2) {
        // If not, print a usage message and exit the program with a non-zero status
        std::cout << "Not enought command line args. Expecting 1 input file name, None give.\n";
        return 1; // Returning 1 typically indicates an error or abnormal termination
    } 

    int m, n; // Variables to store the dimensions of the matrix (rows and columns)
    std::string filename = argv[1]; // Store the filename passed as a command-line argument

    // Call the matrixFromFile function to read the matrix from the file
    // The function returns a pointer to the dynamically allocated matrix
    int** matrix = matrixFromFile(filename, m, n);

    // Display the matrix to the console
    std::cout << "Matrix:\n";
    
    // Loop through each row of the matrix
    for (int i = 0; i < m; ++i) {
        // Loop through each column in the current row
        for (int j = 0; j < n; ++j) {
            // Print the matrix element followed by a tab character for spacing
            std::cout << matrix[i][j] << "\t";
        }
        // After each row, print a newline character to move to the next line
        std::cout << std::endl;
    }

    // Check if the matrix is square (i.e., number of rows equals number of columns)
    if (m == n) {
        // If the matrix is square, calculate the sum of the diagonal elements
        int diagSum = matrixDiagonal(matrix, m);
        
        // Display the calculated sum of diagonal elements
        std::cout << "Sum of diagonal elements: " << diagSum << std::endl;
    } else {
        // If the matrix is not square, notify the user that diagonal sum calculation is skipped
        std::cout << "Matrix is not square, skipping diagonal sum calculation." << std::endl;
    }

    // Free the dynamically allocated memory for the matrix
    // Loop through each row and delete the array allocated for that row
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i]; // Delete the ith row
    }
    
    // Delete the array of pointers that was used to store row pointers
    delete[] matrix;

    // Return 0 to indicate successful termination
    return 0;
}
