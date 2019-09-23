// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the header file for the ZooRecord class
#pragma once
#include "ArrayBag.hpp"

template<class T>
class ZooRecord : public ArrayBag<T> {
public:
    ZooRecord() = default;
    /** pre the input file is expected to be in CSV
     * (comma separated value) format as:
     * "animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,
     * backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
     * @param input_file_name the name of the input file
     * @post adds Animal objects to record as per the data in the input file
     */
    ZooRecord(std::string input_file_name);

    /**@post displays all animals in record, one per line by calling
     * animal's display method*/
    void display();
};
#include "ZooRecord.cpp"