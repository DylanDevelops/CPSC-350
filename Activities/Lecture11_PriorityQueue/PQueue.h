#ifndef P_QUEUE_H
#define P_QUEUE_H

#include "DblList.h"

template<typename T>
class PQueue: private DblList<T> {
    public:
        PQueue(bool isMin);
        virtual ~PQueue();
        void add(T d);
        T remove();
        int size();
        bool isEmpty();
        T peek();
    private:
        bool isMinQ;
};

template <typename T>
PQueue<T>::PQueue(bool isMin) {
    isMinQ = isMin;
}

template <typename T>
PQueue<T>::~PQueue() {

}

template <typename T>
void PQueue<T>::add(T d) {
    if(isEmpty()) {
        DblList<T>::add(d);
        return;
    }

    ListNode<T>* currNode = DblList<T>::m_front;
    int currIdx = 0;

    while(currNode != NULL && currNode->m_data < d) {
        ++currIdx;
        currNode = currNode->m_next;
    }

    DblList<T>::add(currIdx, d);
}

template <typename T>
T PQueue<T>::remove() {
    if(isMinQ) {
        return DblList<T>::removeFront();
    } else {
        return DblList<T>::removeFront();
    }
}

template <typename T>
int PQueue<T>::size() {
    return DblList<T>::size();
}

template <typename T>
bool PQueue<T>::isEmpty() {
    return DblList<T>::isEmpty();
}

template <typename T>
T PQueue<T>::peek() {
    if(isMinQ) {
        return DblList<T>::get(0);
    } else {
        return DblList<T>::get(m_size - 1);
    }
}

#endif