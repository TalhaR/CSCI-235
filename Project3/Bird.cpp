// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the implementation of the Bird class
#include "Bird.hpp"

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