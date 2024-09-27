#include <iostream>

using namespace std;

int main() {
    bool isAlive = true;


    std::string message = isAlive ? "Alive" : "Dead";

    if(isAlive) {
        message = "Alive";
    } else {
        message = "Dead";
    }
}