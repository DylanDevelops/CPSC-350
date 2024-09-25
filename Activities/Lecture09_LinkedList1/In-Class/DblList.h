#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

template <typename T>
class DblList {
    public:
        DblList();
        ~DblList();
        int size();
        bool isEmpty();

        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);

        T removeFront();
        T removeBack();
        T remove();

        T get(int pos);
        
    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template<typename T>
DblList<T>::DblList() {
    // TODO: free up memory for each node in the list
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T>::~DblList() {

}

template <typename T>
int DblList<T>::size() {
    return m_size;
}

template <typename T>
bool DblList<T>::isEmpty() {
    return m_size == 0;
}

template <typename T>
void DblList<T>::addFront(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()) {
        newNode->m_next = m_front;
        m_front->m_prev = newNode;
    } else {
        m_back = newNode;
    }

    m_front = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::addBack(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()) {
        newNode->m_prev = m_front;
        m_front->m_next = newNode;
    } else {
        m_back = newNode;
    }

    m_back = newNode;
    ++m_size;
}

#endif