
// template class for a "naive" queue 

#ifndef AQUEUE_H
#define AQUEUE_H

template <typename T>
class AQueue{
    public:
        AQueue(int s);
        ~AQueue();
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
AQueue<T>::AQueue(int s){
    maxSize = s;
    front = 0; 
    back = -1; 
    count = 0;
    arr = new T[maxSize];
}


template <typename T>
AQueue<T>::~AQueue(){
    delete[] arr;
}

template <typename T>
bool AQueue<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool AQueue<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int AQueue<T>::size(){
    return count;
}

template <typename T>
void AQueue<T>::add(){
    // super naive add method -- will fix with circular queue implementation (CQueue)
    arr[++back] = data;
    ++count;
}
// how to make this a circular queue? 

template <typename T>
T AQueue<T>::remove(){
    // T ret = arr[front]; // keep track of element at front
    // ++front;
    // -- count
    // return ret;
    // same as:
    --count;
    return arr[front++];

}

template <typename T>
T AQueue<T>::peek(){
    return arr[front];
}

#endif  