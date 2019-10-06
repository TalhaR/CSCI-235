// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the header file for the ZooRecord class
#pragma once
#include "List.hpp"
#include "Animal.hpp"

class ZooRecord : public List<Animal*> {
public:
    ZooRecord() = default;
    ~ZooRecord();
    /**parameterized constructor
    @pre the input file is expected to be in CSV (comma separated value) format as:
    "animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbo
    ne,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
    @param input_file_name the name of the input file
    @post adds Animal pointers to Animal-derived dynamic objects to record as
    per the data in the input file
    **/
    ZooRecord(std::string input_file_name);

    /**@post displays all animals in record, one per line by calling appropriate
    object’s display method” **/
    void display();

    /**@post the list is empty and item_count_ == 0*/
    void clear();
    /**
    @param position indicating point of deletion
    @post node at position is deleted, if any. List order is retains
    @return true if there is a node at position to be deleted, false otherwise */
    bool remove(size_t position);
};