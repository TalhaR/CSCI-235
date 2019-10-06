// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation of the Fish class
#include "Fish.hpp"
#include "iostream"

// calling the superconstructor from Animal because it has the same signature
Fish::Fish(std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator) {}
// second paramatized constructor to create a Fish object with all attributes defined
Fish::Fish(bool venomous, std::string name, bool domestic, bool predator)
: Animal(name, domestic, predator), venomous_(venomous) {}

// accessor functions
bool Fish::isVenomous() const {
    return venomous_;
}

// mutator functions
void Fish::setVenomous() {
    venomous_ = true;
}
/**@post prints out the animal's name, domestication
 * and predator status. Along with if the fish is venomous or not
 */
void Fish::display() {
    std::cout << this->getName();
    if (this->isDomestic()){
        std::cout << " is domestic, ";
    } else {
        std::cout << " is not domestic, ";
    }
    if (this->isPredator()){
        std::cout << "it is ";
    } else {
        std::cout << "is not ";
    }
    std::cout << "a predator\nand it is ";
    if (this->isVenomous()){
        std::cout << "venomous.\n\n";
    } else {
        std::cout << "not venomous.\n\n";
    }
}

/**@param a Fish object
 * @post returns true if both objects are of type Fish with same attributes
 */
bool Fish::operator==(const Fish a) const {
    // checks if both objects have the same name
    // and the same status in relation to being 
    // domesticated, being predatorial, along 
    // with if they are venomous or not
    // This will ensure both are actually the same
    // instead of two animals simply having the same name
    if (this->getName() == a.getName()
    && this->isDomestic() == a.isDomestic()
    && this->isPredator() == a.isPredator() 
    && this->isVenomous() == a.isVenomous()){
        return true;
    }
    return false;
}