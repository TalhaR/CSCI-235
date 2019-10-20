#pragma once
#include "Node.hpp"
#include <stddef.h>

template<class T>
class List {
private:
    Node<T>* head;
    size_t length = 0;
public:
    List();
    List(const List& list);
    List()~;

    // mutators
    void add(T item);
    void remove(size_t position);

    // accessors 
    bool isEmpty() const;
    size_t getLength() const;
};

template<class T>
List<T>::List(const List& list){

}

template<class T>
void List<T>::add(T item) {

}

template<class T>
void List<T>::remove(size_t position){

}

template<class T>
bool List<T>::isEmpty() const {
    return this->getLength() == 0;
}

template<class T>
size_t List<T>::getLength() const {

}