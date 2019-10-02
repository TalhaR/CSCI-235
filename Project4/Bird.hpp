// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the header file for the Bird Class
#pragma once
#include "Animal.hpp"

class Bird : public Animal {
private:
    // setting these to false to make sure no problems if 'isAirborne' or 'isAquatic'
    // is called. 
    bool airborne_ = false, aquatic_ = false;
public:
    Bird() = default;
    Bird(std::string name, bool domestic = false, bool predator = false);
    
    // accessor functions
    bool isAirborne() const;
    bool isAquatic() const;

    // mutator functions
    void setAirborne();
    void setAquatic();

    void display() override;
};