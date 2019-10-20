#pragma once

template<class T>
class Node {
private:
    T item;
    Node<T>* nextNode;

public:
    Node() = default;
    Node(T item);
    Node(const Node& otherNode);

    // mutators
    void setNext(Node* nextNode);
    void setItem(T item);

    // accessors
    Node<T>* getNext() const;
    T getItem() const;

};

template<class T>
Node<T>::Node(T item) : item(item), nextNode(nullptr) {}

template<class T>
void Node<T>::setNext(Node<T>* nextNode) {
    this->nextNode = nextNode;
}

template<class T>
void Node<T>::setItem(T item) {
    this->item = item;
}

template<class T>
Node<T>* Node<T>::getNext() const {
    return this->nextNode;
}

template<class T>
T Node<T>::getItem() const {
    return this->item;
}