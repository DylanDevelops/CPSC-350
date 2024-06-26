#include<iostream>
#include<cstdlib>

int main() {
    // Seed value
    srand((unsigned) time(NULL));

    // Loop to get 5 random numbers
    for(int i = 1; i <= 5; i++) {
        // Retrieve a random number between 100 and 200
        int random = 100 + (rand() % 101);

        std::cout << random << std::endl;
    }

    return 1;
}