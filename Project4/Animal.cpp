// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Animal class
#include "Animal.hpp" 
#include <iostream>

Animal::Animal() {
    // giving the object default values to make sure no errors 
    // in case the getters were called
    name = "";
    domestic = false;
    predator = false;
}

Animal::Animal(std::string name, bool domestic, bool predator)
: name(name), domestic(domestic), predator(predator) {}

std::string Animal::getName() const {
    return name;
}

bool Animal::isDomestic() const {
    return domestic;
}

bool Animal::isPredator() const {
    return predator;
}

void Animal::setName(std::string name) {
    this->name = name;
}

void Animal::setDomestic() { // sets Animal as Domesticated 
    this->domestic = true;
}

void Animal::setPredator() { // sets Aniaml as a Predator 
    this->predator = true;
}