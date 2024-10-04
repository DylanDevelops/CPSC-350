#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 9;

    string answer = num % 2 ? "O" : "E";

    std::cout << answer << std::endl;
}