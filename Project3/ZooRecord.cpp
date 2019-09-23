// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the implementation file for the ZooRecord class
#include "ZooRecord.hpp"
#include <fstream>
#include <sstream>

ZooRecord::ZooRecord(std::string input_file_name){
    // creates the inputfile stream based on the path passed into function
    std::ifstream infile;
    infile.open(input_file_name);

    // method will only proceed if the file was found
    if(infile.good()){
        std::string name, line, s, temp;
        bool predator, domestic;

        // get rid of first line because it's not relevant
        getline(infile, temp);

        while(getline(infile, line)){
            // using stringstream to process each word of an individual line
            std::stringstream s(line);
            // using count to keep track of input #
            // since there should only be 18 inputs per line
            int count = 0; 
        
            // stores each word/number from the stringstream
            // into a temp string value
            while(getline(s, temp, ',')){
                // first word/input is the name of the animal
                if (count == 0) name = temp;
                // eighth input is whether the animal is a predator or not
                if (count == 7) {
                    if (temp == "1") {
                        predator = true;
                    } else {
                        predator = false;
                    }
                }
                // sixteenth input is whether the animal is domesticated
                if (count == 15) {
                    if (temp == "1"){
                        domestic = true;
                    } else {
                        domestic = false;
                    }
                }
                count++;
            }
            // creates an object and adds to the ZooRecord
            // based on the information gathered from the CSV.file
            this->add(Animal(name, domestic, predator));
        }
    } else {
        std::cout << "Cannot open file\n";
    }
    infile.close();
}

void ZooRecord::display() {
    // if the ZooRecord is empty there is nothing to display
    // so it's best to just leave the method
    if (this->isEmpty()) return;

    // iterates through the arraybag starting from 0
    // working up to the item_count_ and calls the
    // respective Animal's display method to print 
    // what their name is along with if they're a 
    // predator or domesticated.
    for (int i = 0; i < this->item_count_; i++){
        // calling the display method of the Animal class
        // for each individual Animal in the ZooRecord
        // that method handles the printing of output
        this->items_[i].display();
    }
}
