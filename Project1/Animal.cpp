// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 1

// This is the implementation of the Animal class
#include "Animal.hpp" 

Animal::Animal(){
    // giving the object default values to make sure no errors 
    // in case the getters were called
    this->name = "";
    this->domestic = false;
    this->predator = false;
}

Animal::Animal(std::string name, bool domestic, bool predator)
: name(name), domestic(domestic), predator(predator){}

std::string Animal::getName() const {
    return this->name;
}
bool Animal::isDomestic() const{
    return this->domestic;
}
bool Animal::isPredator() const{
    return this->predator;
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