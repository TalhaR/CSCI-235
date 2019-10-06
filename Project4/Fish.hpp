// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the header file for the Fish Class
#pragma once
#include "Animal.hpp"

class Fish : public Animal {
private:
    // setting this to false by default because most fish
    // aren't venomous and if they were, the setVenomous method
    // will be called before to set this value to true
    bool venomous_ = false;
public:
    Fish() = default;
    Fish(std::string name, bool domestic = false, bool predator = false);
    Fish(bool venomous, std::string name, bool domestic = false, bool predator = false);
    
    // accessor functions
    bool isVenomous() const;

    // mutator functions
    void setVenomous();
    /**@post prints out the animal's name, domestication
    * and predator status. Along with if the fish is venomous or not
    */
    void display() override;
    
    /**@param a Fish object
     * @post returns true if both objects are of type Fish with same attributes
     */
    bool operator==(const Fish a) const;
};