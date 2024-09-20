#ifndef TSTACK_H
#define TSTACK_H

template <typename T>
class TStack {
    public:
        TStack(int initialSize);
        ~TStack();

        // interface
        void push(T c); // add c o the top of stack
        T pop(); // removes the element sitting at the top of the stack
        T peek(); // returns the element sitting at the top of the stack

        // helper methods
        bool isFull(); 
        bool isEmpty();
        int actualSize(); // how many elements are actually in the stack
        int maxSize();

    private:
        T* stackArr;
        int count; // number of elements currently in the stack
        int max; // max number of elements to be held int he stack
        int top; // index of the top element
};

template <typename T>
TStack<T>::TStack(int initialSize) {
    stackArr = new T[initialSize];
    max = initialSize;
    count = 0;
    top = -1;
}

template <typename T>
TStack<T>::~TStack() {
    delete[] stackArr;
}

template <typename T>
void TStack<T>::push(T c) {
    if(isFull()) {
        // increase size or stackArr
        T* temp = new T[2 * max];
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

template <typename T>
T TStack<T>::pop() {
    --count;
    return stackArr[top--];
}

template <typename T>
T TStack<T>::peek() {
    return stackArr[top];
}

template <typename T>
bool TStack<T>::isFull() {
    return (count == max);
}

template <typename T>
bool TStack<T>::isEmpty() {
    return (count == 0);
}

template <typename T>
int TStack<T>::actualSize() {
    return count;
}

template <typename T>
int TStack<T>::maxSize() {
    return max;
}

#endif