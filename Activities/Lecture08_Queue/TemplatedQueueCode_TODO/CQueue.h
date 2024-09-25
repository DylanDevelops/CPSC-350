
#ifndef CQUEUE_H
#define CQUEUE_H

template <typename T>
class CQueue{
    public:
        CQueue(int s);
        ~CQueue();
        void add(T data); // add to the back of the queue
        T remove(); // remove element from the front
        T peek(); // return the element at the front
        bool isFull();
        bool isEmpty();
        int size(); // count of elements currently in queue
    private:
        T* arr;
        int maxSize; // size of the array
        int front;
        int back;
        int count;

};


template <typename T>
CQueue<T>::CQueue(int s){
    maxSize = s;
    front = 0;
    back = -1;
    count = 0;
    arr = new T[maxSize];
}


template <typename T>
CQueue<T>::~CQueue(){
    delete[] arr;
}

template <typename T>
bool CQueue<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool CQueue<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int CQueue<T>::size(){
    return count;
}

// how to make this a circular queue?

// 1 check if arr is full, retrurn
// else if back > max size move input to arr[0]
//
template <typename T>
void CQueue<T>::add(T data){
    if(!isFull()) {
        if(back == (maxSize - 1)) { // is the back at the last cell of the array
            back = -1; // if the back was at the end, change back index tracker to -1
        }
        arr[++back] = data;
        ++count;
    }
}


template <typename T>
T CQueue<T>::remove(){
    T ret = arr[front];
    ++front;
    --count;
    if(front == maxSize) {
        front = 0;
    }
    return ret;
}

template <typename T>
T CQueue<T>::peek(){
    return arr[front];
}

#endif
