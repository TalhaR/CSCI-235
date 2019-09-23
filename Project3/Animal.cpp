// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the implementation of the Animal class
#include "Animal.hpp" 
#include <iostream>

Animal::Animal(){
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
bool Animal::isDomestic() const{
    return domestic;
}
bool Animal::isPredator() const{
    return predator;
}

void Animal::setName(std::string name){
    this->name = name;
}
void Animal::setDomestic(){ // sets Animal as Domesticated 
    this->domestic = true;
}
void Animal::setPredator(){ // sets Aniaml as a Predator 
    this->predator = true;
}

void Animal::display(){
    // will print out the name, 
    // domestication status and if
    // the animal is a predator or not
    std::cout << this->getName();
    if (this->isDomestic()){
        std::cout << " is domestic";
    } else {
        std::cout << " is not domestic";
    }
    std::cout << " and it is ";
    if (!this->isPredator()){
        std::cout << "not ";
    }
    std::cout << "a predator\n";
}

bool Animal::operator==(const Animal a) const {
    // checks if both objects have the same name
    // and the same status in relation to being 
    // domesticated and being predatorial.
    // This will ensure both are actually the same
    // instead of two animals simply having the same name
    if (this->getName() == a.getName()
    && this->isDomestic() == a.isDomestic()
    && this->isPredator() == a.isPredator()) {
        return true;
    }
    return false;
}