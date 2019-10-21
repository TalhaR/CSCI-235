#pragma once
#include "Node.hpp"
#include "Exception.hpp"
#include <iostream>

template<class T>
class List {
private:
    Node<T>* head;
    size_t item_count = 0;
public:
    List();
    List(const List<T>& list);
    ~List();

    // mutators
    void add(T item);
    void remove(size_t position);
    void clear();

    // accessors 
    bool isEmpty() const;
    size_t getLength() const;
    T getItem(size_t position) const;
};

template<class T>
List<T>::List() : head(nullptr) {}

template<class T>
List<T>::List(const List<T>& list){

}

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
void List<T>::add(T item) {
    Node<T>* tempPtr = new Node<T>(item);
    tempPtr->setNext(head);

    head = tempPtr;
    item_count++;
}

template<class T>
void List<T>::remove(size_t position) {
    if(position >= item_count) return;

    Node<T>* tempPtr;
    Node<T>* current = head;

    for(int i = 0; i < position-1; i++){
        current = current->getNext();
    }

    tempPtr = current->getNext()->getNext();
    
    delete current->getNext();
    current->getNext()->setNext(nullptr);

    current->setNext(tempPtr);
    item_count--;
}

template<class T>
void List<T>::clear() {
    if(item_count == 0) return;

    Node<T>* tempPtr;

    while(tempPtr != nullptr) {
        tempPtr = head->getNext();
        delete head;

        head = tempPtr;
    }
    item_count = 0;
}

template<class T>
T List<T>::getItem(size_t position) const {
    if (position >= item_count) {
        throw(Exception("getItem() called with an invalid Position"));
    }

    Node<T>* tempPtr = head;

    for(int i = 0; i < position; i++) {
        tempPtr = tempPtr->getNext();
    }

    return tempPtr->getItem();
}

template<class T>
size_t List<T>::getLength() const {
    return item_count;
}

template<class T>
bool List<T>::isEmpty() const {
    return item_count == 0;
}