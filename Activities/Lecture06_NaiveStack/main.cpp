#include "NaiveCharStack.h"
#include <iostream>

int main() {
    // Create the naive stack

    // on the call stack
    NaiveCharStack myStack(5);
    std::cout << myStack.actualSize() << std::endl;

    myStack.push('H');
    myStack.push('E');
    myStack.push('L');
    myStack.push('L');
    myStack.push('O');

    std::cout << myStack.actualSize() << std::endl;
    std::cout << myStack.peek() << std::endl;

    // empty out the stack
    while(!myStack.isEmpty()) {
        std::cout << myStack.pop() << "\t";
    }

    std::cout << std::endl;

    std::cout << myStack.actualSize() << std::endl;
}