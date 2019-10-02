// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the header file for the Mammal Class
#pragma once
#include "Animal.hpp"

class Mammal : public Animal {
    private:
        // setting these to false to make sure no problems if any method
        // is called that would ask for one of these values, before the 
        // appropriate setter method is used to set one of these values to true.
        bool hair_ = false, toothed_ = false, tail_ = false, fins_ = false;
        bool airborne_ = false, aquatic_ = false;
        // setting this to 0 to make sure no issue if 'legs()' is called 
        // when 'setLegs(int legs)' wasn't used to set appropriate amount
        // of legs
        int legs_ = 0;
    public:
        Mammal() = default;
        Mammal(std::string name, bool domestic = false, bool predator = false);
        
        // accessor functions. All have const after to indicate they're not modifying anything
        bool hasHair() const;
        bool isToothed() const;
        bool isAirborne() const;
        bool isAquatic() const;
        bool hasFins() const;
        bool hasTail() const;
        int legs() const;

        // mutator functions
        void setHair();
        void setToothed();
        void setAirborne();
        void setAquatic();
        void setFins();
        void setTail();
        void setLegs(int legs);
};