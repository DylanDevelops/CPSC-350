#ifndef NAIVE_CHAR_STACK_H
#define NAIVE_CHAR_STACK_H

class NaiveCharStack {
    public:
        NaiveCharStack(int initialSize);
        ~NaiveCharStack();

        // interface
        void push(char c); // add c o the top of stack
        char pop(); // removes the element sitting at the top of the stack
        char peek(); // returns the element sitting at the top of the stack

        // helper methods
        bool isFull(); 
        bool isEmpty();
        int actualSize(); // how many elements are actually in the stack
        int maxSize();

    private:
        char* stackArr;
        int count; // number of elements currently in the stack
        int max; // max number of elements to be held int he stack
        int top; // index of the top element
};

#endif