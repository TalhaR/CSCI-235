// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Mammal class
#include "Mammal.hpp"
#include <iostream>

// calling the superconstructor from Animal because it has the same signature
Mammal::Mammal(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}

// accessor functions
bool Mammal::hasHair() const {
    return hair_;
}
bool Mammal::isToothed() const {
    return toothed_;
}
bool Mammal::isAirborne() const {
    return airborne_;
}
bool Mammal::isAquatic() const {
    return aquatic_;
}
bool Mammal::hasFins() const {
    return fins_;
}
bool Mammal::hasTail() const {
    return tail_;
}
int Mammal::legs() const {
    return legs_;
}

// mutator functions
void Mammal::setHair(){
    hair_ = true;
}
void Mammal::setToothed(){
    toothed_ = true;
}
void Mammal::setAirborne(){
    airborne_ = true;
}
void Mammal::setAquatic(){
    aquatic_ = true;
}
void Mammal::setFins(){
    fins_ = true;
}
void Mammal::setTail(){
    tail_ = true;
}
void Mammal::setLegs(int legs){
    legs_ = legs;
}

void Mammal::display() {
    std::cout << this->getName();
    if (this->isDomestic()){
        std::cout << " is domestic and ";
    } else {
        std::cout << " is not domestic and ";
    }
    if (this->isPredator()){
        std::cout << "it is ";
    } else {
        std::cout << "is not ";
    }
    std::cout << "a predator,\n";
    if (this->isAirborne()){
        std::cout << "it is airborne ";
    } else {
        std::cout << "It is not airborne ";
    }
    if (this->isAquatic()){
        std::cout << "it is aquatic,\n";
    } else {
        std::cout << "It is not aquatic,\n";
    }
    if (this->hasHair()){
        std::cout << "it has hair, ";
    } else {
        std::cout << "It has no hair, ";
    }
    if (this->isToothed()){
        std::cout << "teeth, ";
    } else {
        std::cout << "no teeth, ";
    }
    if (this->hasFins()){
        std::cout << "fins, ";
    } else {
        std::cout << "no fins, ";
    }
    if (this->hasTail()){
        std::cout << "tail, ";
    } else {
        std::cout << "no tail, ";
    }
    if (this->legs()){
        std::cout << "and " << legs() << " legs.\n\n";
    } else {
        std::cout << "no legs.\n\n";
    }
}