// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Fish class
#include "Fish.hpp"
#include "iostream"

// calling the superconstructor from Animal because it has the same signature
Fish::Fish(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}

// accessor functions
bool Fish::isVenomous() const {
    return venomous_;
}

// mutator functions
void Fish::setVenomous() {
    venomous_ = true;
}

void Fish::display() {
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
    std::cout << "a predator\n and it is ";
    if (this->isVenomous()){
        std::cout << "venomous.\n\n";
    } else {
        std::cout << "not venomous.\n\n";
    }
}