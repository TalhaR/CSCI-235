// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the header file for the Animal Class
#pragma once
#include <string>

class Animal{
    protected:
        std::string name;
        bool domestic, predator;
    public:
        // no-argument constructor 
        Animal();
        // parameterized constructor which sets initial values for object
        Animal(std::string name, bool domestic = false, bool predator = false);
        // getters/accessors to see private variables
        std::string getName() const;
        bool isDomestic() const;
        bool isPredator() const;
        // setters/mutators to change private variables
        void setName(std::string name);
        void setDomestic();
        void setPredator();  

        /**@post displays animal data in the form:
         * "animal_name is [not] domestic and [it is / is not] a predator\n"
         */
        void display();

        bool operator==(const Animal a) const;
};