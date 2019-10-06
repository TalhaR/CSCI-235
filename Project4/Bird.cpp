// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Bird class
#include "Bird.hpp"
#include <iostream>

// calling the superconstructor from Animal because it has the same signature
Bird::Bird(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}

// second paramatized constructor to create a Bird object with all attributes defined
Bird::Bird(bool airborne, bool aquatic, std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator), airborne_(airborne), aquatic_(aquatic) {}

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

/**@post prints out the animal's name, domestication
 * and predator status. Along with if the Bird is
 * airborne and/or aquatic
 */
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
    std::cout << "a predator,\nit is ";
    if (this->isAirborne()){
        std::cout << "airborne";
    } else {
        std::cout << "not airborne";
    }
    std::cout << " and it is ";
    if (this->isAquatic()){
        std::cout << "aquatic\n\n";
    } else {
        std::cout << "not aquatic\n\n";
    }
}

/**@param a Bird object
 * @post returns true if both objects are of type Bird with same attributes
 */
bool Bird::operator==(const Bird a) const {
    // checks if both objects have the same name
    // and the same status in relation to being 
    // domesticated, being predatorial, along 
    // with if they are either airborne or aquatic
    // This will ensure both are actually the same
    // instead of two animals simply having the same name
    if (this->getName() == a.getName()
    && this->isDomestic() == a.isDomestic()
    && this->isPredator() == a.isPredator() 
    && this->isAirborne() == a.isAirborne()
    && this->isAquatic() == a.isAquatic()){
        return true;
    }
    return false;
}