/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA3: Do You See What I See?
*/

#ifndef T_STACK_H
#define T_STACK_H
#include <iostream> 

template <typename T>
class MonoStack {
    public:
        MonoStack(int iSize, char o);
        ~MonoStack();
        void push(T c);
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        int count;
        int maxSize;
        char type;
        int top;
};

template <typename T>
MonoStack<T>::MonoStack(int iSize, char o) {
    stackArr = new T[iSize];
    maxSize = iSize;
    type = std::tolower(o);
    count = 0;
    top = -1;
}

template <typename T>
MonoStack<T>::~MonoStack() {
    delete[] stackArr;
}

template <typename T>
bool MonoStack<T>::isFull() {
    return (count == maxSize);
}

template <typename T>
bool MonoStack<T>::isEmpty() {
    return (count == 0);
}

template <typename T>
int MonoStack<T>::size() {
    return count;
}

template <typename T>
void MonoStack<T>::push(T c) {
    if(type == 'i') {
        // Monotonically Increasing
        while(!isEmpty() && stackArr[top] >= c) {
            pop();
        }
    } else if(type == 'd') {
        // Monotonically Decreasing
        while(!isEmpty() && stackArr[top] <= c) {
            pop();
        }
    }

    if(isFull()) {
        T* temp = new T[2 * maxSize];

        for(int i = 0; i < maxSize; ++i) {
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }

    stackArr[++top] = c;
    ++count;
}

template <typename T>
T MonoStack<T>::pop() {
    --count;
    return stackArr[top--];
}

template <typename T>
T MonoStack<T>::peek() {
    return stackArr[top];
}

#endif