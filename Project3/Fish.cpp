// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the implementation of the Fish class
#include "Fish.hpp"

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