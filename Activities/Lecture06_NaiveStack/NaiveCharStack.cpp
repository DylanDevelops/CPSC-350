#include "NaiveCharStack.h"

NaiveCharStack::NaiveCharStack(int initialSize) {
    stackArr = new char[initialSize];
    max = initialSize;
    count = 0;
    top = -1;
}

NaiveCharStack::~NaiveCharStack() {
    delete[] stackArr;
}

void NaiveCharStack::push(char c) {
    if(isFull()) {
        // increase size or stackArr
        char* temp = new char[2 * max];
        for(int i = 0; i < max; ++i) {
            temp[i] = stackArr[i];
        }

        max *= 2;
        delete[] stackArr;
        stackArr = temp;
    }

    stackArr[++top] = c;
    ++count;
}

char NaiveCharStack::pop() {
    --count;
    return stackArr[top--];
}

char NaiveCharStack::peek() {
    return stackArr[top];
}

bool NaiveCharStack::isFull() {
    return (count == max);
}

bool NaiveCharStack::isEmpty() {
    return (count == 0);
}

int NaiveCharStack::actualSize() {
    return count;
}

int NaiveCharStack::maxSize() {
    return max;
}
