#include <iostream>

int main() {
    for(int i = 1; i <= 100; i++) {
        bool mOf3 = false;
        bool mOf5 = false;

        if(i % 3 == 0) {
            mOf3 = true;
        }

        if(i % 5 == 0) {
            mOf5 = true;
        }

        if(mOf3 && mOf5) {
            std::cout << "FizzBuzz" << std::endl;
        } else if(mOf3) {
            std::cout << "Fizz" << std::endl;
        } else if(mOf5) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }

    return 0;
}