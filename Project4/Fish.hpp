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
        
        // accessor functions
        bool isVenomous() const;

        // mutator functions
        void setVenomous();
};