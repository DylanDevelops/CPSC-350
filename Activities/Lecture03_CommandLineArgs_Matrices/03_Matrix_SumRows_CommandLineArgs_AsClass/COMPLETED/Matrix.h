// Header guards
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:
        int** matrix;
        int rows;
        int cols;

    public:
        // Constructor
        Matrix(int r, int c);

        // Destructor
        ~Matrix();

        // Method to fill the matrix with random integers
        void randomMatrix();

        // Method to calculate the sum of each row
        void sumRows(int* rowSums);

        // Method to display the matrix
        void displayMatrix();

    
}; // don't forget this ;, I always do! 

#endif // end of header file & header guard 
