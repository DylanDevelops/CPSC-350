/*
	Write a C++ program that prompts the user for the length, n, of an array, arr. 
	Dynamically allocate the array to be of size n and initialize the contents to the first n odd numbers (starting from 1).
	After that, print the contents of the array, and finally, deallocate the array.
*/

#include <iostream>

int main() {
    int n;  // Variable to hold the length of the array

    // Prompt the user for the length of the array
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Dynamically allocate the array of size n
    int* arr = new int[n];

    // Initialize the array with the first n odd numbers
    for (int i = 0; i < n; ++i) {
        arr[i] = 2 * i + 1;  // Formula to get the i-th odd number
    }

    // Print the contents of the array
    std::cout << "The first " << n << " odd numbers are: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate the array
    delete[] arr;

    return 0;
}
