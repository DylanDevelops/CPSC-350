/*
Write the C++ code to prompt the user for the length, n, of an array, arr. 
Dynamically allocate the array to be of size n and initialize the contents to 
the first n multiples of 2. Finally, deallocate the array.
*/

#include <iostream>
// using namespace std;
int main() {
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // dynamically allocate the array
    int *arr = new int[n];  
    for (int i = 0; i < n; i++) {
        arr[i] = 2 * i;  
    }

    // printing
    std::cout << arr << std::endl;      // what gets printed here? 
    
    for (int i = 0; i<n; i++){          // vs here
        std::cout << arr[i] << std::endl;
    }


    // deallocate the array -- delete it from the heap 
    delete[] arr;

    return 0;
}
