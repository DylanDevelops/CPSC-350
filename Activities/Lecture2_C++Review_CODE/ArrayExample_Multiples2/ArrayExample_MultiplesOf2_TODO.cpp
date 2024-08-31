/*
Write the C++ code to prompt the user for the length, n, of an array, arr. 
Dynamically allocate the array to be of size n and initialize the contents to 
the first n multiples of 2. Finally, deallocate the array.
*/

#include <iostream>

int main() {
    int n;

    std::cout << "Enter the size: ";
    std::cin >> n;

    int* myArr = new int[n];

    for(int i = 0; i < n; ++i) {
        myArr[i] = 2*i;
    }

    std::cout << myArr << std::endl;

    for(int i = 0; i < n; ++i) {
        std::cout << myArr[i] << " ";
    }

    std::cout << std::endl;

    delete[] myArr;

    return 0;
}