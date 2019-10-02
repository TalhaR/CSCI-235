// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Mammal class
#include "Mammal.hpp"

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