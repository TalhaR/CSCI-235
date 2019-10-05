// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Bird class
#include "Bird.hpp"
#include <iostream>

// calling the superconstructor from Animal because it has the same signature
Bird::Bird(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}

// accessor functions
bool Bird::isAirborne() const {
    return airborne_;
}
bool Bird::isAquatic() const {
    return aquatic_;
}

// mutator functions
void Bird::setAirborne() {
    airborne_ = true;
}
void Bird::setAquatic() {
    aquatic_ = true;
}

void Bird::display() {
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
    if (this->isAirborne()){
        std::cout << "airbone";
    } else {
        std::cout << "not airborne";
    }
    std::cout << " and it is ";
    if (this->isAquatic()){
        std::cout << "aquatic.\n\n";
    } else {
        std::cout << "not aquatic.\n\n";
    }
}