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
        T remove(int pos);

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
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
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

template <typename T>
void DblList<T>::add(int pos, T data) {
    if(isEmpty()) {
        addFront(data);
    } else if(pos == 0) {
        addFront(data);
    } else if(pos >= m_size) {
        addBack(data);
    } else {
        ListNode<T>* current = m_front;
        int cPos = 0;

        while(cPos != pos) {
            current = current->m_next;
            ++cPos;
        }

        ListNode* newNode = new ListNode<T>(data);

        current->m_prev->m_next = newNode;
        newNode->m_prev = current->m_prev;
        current->m_prev = newNode;
        ++m_size;
    }
}

template<typename T>
T DblList<T>::removeFront() {
    T data = m_back->m_data;

    if(m_size == 1) {
        delete m_front; // Calls the destructor for the node at m_front

        m_front = NULL;
        m_back = NULL;
    } else {
        ListNode<T>* currFront = m_front;

        m_front = currFront->m_next;
        m_front->m_prev = NULL;

        delete currFront;
    }

    --m_size;
    return data;
}

template<typename T>
T DblList<T>::removeBack() {
    T data = m_back->m_data;

    if(m_size == 1) {
        delete m_back; // Calls the destructor for the node at m_back

        m_front = NULL;
        m_back = NULL;
    } else {
        ListNode<T>* currBack = m_back;

        m_back = currFront->m_prev;
        m_back->m_next = NULL;

        delete currBack;
    }

    --m_size;
    return data;
}

template<typename T>
T DblList<T>::remove(int pos) {
    T data;

    if(pos == 0) {
        data = removeFront();
    } else if(pos >= (m_size - 1)) {
        data = removeBack();
    } else {
        ListNode<T>* current = m_front;
        int cPos = 0;

        while(cPos != pos) {
            current = current->m_next;
            ++cPos;
        }

        data = current->m_data;
        current->m_prev->m_next = current->m_next;
        current->m_next->m_prev = current->m_prev;

        delete current;
        --m_size;
    }

    return data;
}

template <typename T>
T DblList<T>::get(int pos) {
    ListNode<T>* current = m_front;
    int cPos = 0;

    while(cPos != pos) {
        current = current->m_next;
        ++cPos;
    }

    return current->m_data;
}

#endif