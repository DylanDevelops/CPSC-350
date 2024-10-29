/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA4: Genetic Palindromes
*/

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include <cstdlib>

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        int size();
        bool isEmpty();
        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);
        T get(int pos);
        T removeFront();
        T removeBack();
        T remove(int pos);

    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template<typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T>::~DblList(){
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

template<typename T>
int DblList<T>::size(){
    return m_size;
}

template<typename T>
bool DblList<T>::isEmpty(){
    return (m_size == 0);
}

template <typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data); // create new node (aka newNode)
		// set newNode’s prev pointer to NULL (done in constructor)
    if (!isEmpty()){ // if linked list is not empty 
        newNode -> m_next = m_front; // set newNode’s next pointer to the old front (aka oldFront)
        m_front -> m_prev = newNode; // set oldFront’s prev pointer to newNode 
    } else { // if list is empty (newNode is 1st node) 
        m_back = newNode; // then set back to newNode too
    }
    m_front = newNode; // set front to newNode regardless 
    ++m_size; // add one to size 
}

template<typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        newNode->m_prev = m_back;
        m_back->m_next = newNode;
    }else{
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template<typename T>
void DblList<T>::add(int pos, T data){
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
        ListNode<T>* newNode = new ListNode<T>(data);
        current->m_prev->m_next = newNode;
        newNode->m_prev = current->m_prev;
        current->m_prev = newNode;
        newNode->m_next = current;
        ++m_size;
    }
}

template<typename T>
T DblList<T>::removeFront(){
    //make sure not empty
    if(isEmpty()) {
        throw std::out_of_range("List is empty");
    }

    T data = m_front->m_data;
    if(m_size == 1){
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front;
        m_front = m_front->m_next;
        m_front->m_prev = NULL;
        delete currFront;
    }
    --m_size;
    return data;
}

template<typename T>
T DblList<T>::removeBack(){
    //make sure not empty
    if(isEmpty()) {
        throw std::out_of_range("List is empty");
    }

    T data = m_back->m_data;

    if(m_size == 1) {
        delete m_back;
        m_front = NULL;
        m_back = NULL;
    } else {
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        delete currBack;
    }

    --m_size;
    return data;
}

template<typename T>
T DblList<T>::remove(int pos){
    //make sure not empty
    if(isEmpty()) {
        throw std::out_of_range("List is empty");
    }

    if(pos < 0 || pos >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    T data;
    if (pos == 0) {
        data = removeFront();
    } else if(pos >= m_size -1) {
        data = removeBack();
    } else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
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

template<typename T>
T DblList<T>::get(int pos){
    //is pos in range, etc.
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    return current->m_data;
}


#endif