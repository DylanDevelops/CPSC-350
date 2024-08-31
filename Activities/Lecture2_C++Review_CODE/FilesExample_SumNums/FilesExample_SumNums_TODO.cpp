
/*
Write a program that reads integers from a file called numbers.txt, sums them up, and writes the result to a file called sum.txt.
*/

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("numbers.txt");
    std::ofstream outFile("sum.text");

    int number, sum = 0;

    if(inFile.is_open()) {
        while (inFile >> number)
        {
            sum += number;
        }
        inFile.close();
    } else {
        std::cout << "Something went wrong when opening the file!" << std::endl;
        return 1;
    }

    if(outFile.is_open()) {
        outFile << "Sum: " << sum << std::endl;
        outFile.close();
    } else {
        std::cout << "Something went wrong when opening the output file! Here is the sum: " << sum << std::endl;
        return 1;
    }

    return 0;
}