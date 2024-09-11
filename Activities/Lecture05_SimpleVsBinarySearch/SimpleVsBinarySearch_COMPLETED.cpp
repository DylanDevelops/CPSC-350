#include <iostream>
using namespace std; 

// simple search
// return the first index of the array that contains value "key"
// how bad is the performance of this algo?
    // worst case, I need to iterate thru the entire arr bc "key" is the last 
        // element. So we'd have to do "len" amount of comparisons -> Oh(n)
    // best case, "key" is the first element so constant -> Omega(1)
int simpleSearch(int* arr, int len, int key){
    int idx = -1;
    int comparisons = 0;
    for (int i = 0; i < len; ++i){
        ++comparisons;
        if (arr[i] == key){
            idx= i;
            break;
        }
    }
    cout << "I did " << comparisons << " comparisons" << endl;
    return idx;
} 

// assumes array is ordered/ sorted!!! 
// return the first index of the array that contains value "key"
// worst case -> Oh(log n)
// best case -> Omega(1) // if key is in "middle" the first time 
int binarySearch(int* arr, int len, int key){
    int right = len;
    int left = 0;
    int idx = -1;
    int comparisons = 0;
    while (right >= left){
        ++ comparisons;
        int middle = (right + left) / 2; // find/ update middle 
        if (arr[middle] == key){
            idx = middle;
            break;
        } 
        // if key not found then decide new bounds 
        if (key < arr[middle]){ 
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    cout << "I did " << comparisons << " comparisons" << endl;

    return idx;
}


int main(){
    cout << "Populating array." << endl;
    int len = 10000000;
    int key = 800000;

    int* myArr = new int[len];
    for (int i = 0; i < len; ++i){
        myArr[i] = i*2;
    }
    cout << "Starting simple search..." << endl;
    cout << "Found the key " << key << " at index " << simpleSearch(myArr, len, key) << endl;
    cout << "Ending simple search..." << endl;

    cout << "Starting binary search..." << endl;
    cout << "Found the key " << key << " at index " << binarySearch(myArr, len, key) << endl;
    cout << "Ending binary search..." << endl;

    delete[] myArr; // clean up after yourself :) 
    return 0;
}