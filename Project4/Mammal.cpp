// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Mammal class
#include "Mammal.hpp"
#include <iostream>

// calling the superconstructor from Animal because it has the same signature
Mammal::Mammal(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}
// second paramatized constructor to create a Mammal object with all attributes defined
Mammal::Mammal(bool hair, bool toothed, bool tail, bool fins, 
bool airborne, bool aquatic, int legs, std::string name, bool domestic, bool predator) 
: Animal(name, domestic, predator), hair_(hair), toothed_(toothed), tail_(tail), fins_(fins), 
airborne_(airborne), aquatic_(aquatic), legs_(legs) {}

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
/**@post prints out the animal's name, domestication
 * and predator status. Along with if the Mammal
 * has features such as teeth, hair, fins, a tail
 * and the number of legs
 */
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
        std::cout << "it is airborne and ";
    } else {
        std::cout << "it is not airborne and ";
    }
    if (this->isAquatic()){
        std::cout << "it is aquatic,\n";
    } else {
        std::cout << "it is not aquatic,\n";
    }
    if (this->hasHair()){
        std::cout << "it has hair, ";
    } else {
        std::cout << "it has no hair, ";
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
        std::cout << "tail ";
    } else {
        std::cout << "no tail ";
    }
    if (this->legs()){
        std::cout << "and " << legs() << " legs.\n\n";
    } else {
        std::cout << "and no legs.\n\n";
    }
}

/**@param a Mammal object
 * @post returns true if both objects are of type Mammal with same attributes
 */
bool Mammal::operator==(const Mammal a) const {
    // checks if both objects have the same name
    // and the same status in relation to being 
    // domesticated, being predatorial, along 
    // with if they are airborne, aquatic,
    // have fins, have tails or the same number
    // of legs.
    // This will ensure both are actually the same
    // instead of two animals simply having the same name
    if (this->getName() == a.getName()
    && this->isDomestic() == a.isDomestic()
    && this->isPredator() == a.isPredator() 
    && this->hasHair() == a.hasHair()
    && this->isToothed() == a.isToothed()
    && this->isAirborne() == a.isAirborne()
    && this->isAquatic() == a.isAquatic()
    && this->hasFins() == a.hasFins()
    && this->hasTail() == a.hasTail()
    && this->legs() == a.legs()){
        return true;
    }
    return false;
}