// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 4

// This is the implementation file for the ZooRecord class
#include "ZooRecord.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include <fstream>
#include <sstream>

// destructor
ZooRecord::~ZooRecord() {
    clear();
}

/**parameterized constructor
@pre the input file is expected to be in CSV (comma separated value) format as:
"animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbo
ne,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
@param input_file_name the name of the input file
@post adds Animal pointers to Animal-derived dynamic objects to record as
per the data in the input file
**/
ZooRecord::ZooRecord(std::string input_file_name){
    // creates the inputfile stream based on the path passed into function
    std::ifstream infile;
    infile.open(input_file_name);

    // method will only proceed if the file was found
    if(infile.good()){
        std::string name, line, s, temp;
        bool predator, domestic, venomous;
        bool airborne, aquatic;
        bool hair, toothed, fins, tail;
        int classType, legs;

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
            while(getline(s, temp, ',')) {
                // first word/input is the name of the animal
                if (count == 0) name = temp;
                // hair
                if (count == 1) {
                    temp == "1" ? hair = true : hair = false;
                }
                // airborne
                if (count == 5) {
                    temp == "1" ? airborne = true : airborne = false;
                }
                // aquatic
                if (count == 6) {
                    temp == "1" ? aquatic = true : aquatic = false;
                }
                // eighth input is whether the animal is a predator or not
                if (count == 7) {
                    temp == "1" ? predator = true : predator = false;
                }
                // toothed
                if (count == 8) {
                    temp == "1" ? toothed = true : toothed = false;
                }
                // eleventh input is whether the animal is venomous
                if (count == 11) {
                    temp == "1" ? venomous = true : venomous = false;
                }
                // fins
                if (count == 12) {
                    temp == "1" ? fins = true : fins = false;
                }
                // legs
                if (count == 13) {
                    if (temp == "0") {
                        legs = 0;
                    }
                    if (temp == "1") {
                        legs = 1;
                    }
                    if (temp == "2") {
                        legs = 2;
                    }
                    if (temp == "3") {
                        legs = 3;
                    }
                    if (temp == "4") {
                        legs = 4;
                    }
                    if (temp == "5") {
                        legs = 5;
                    }
                    if (temp == "6") {
                        legs = 6;
                    }
                    if (temp == "7") {
                        legs = 7;
                    }
                    if (temp == "8") {
                        legs = 8;
                    }
                }
                // fifteenth input is whether the animal has a tail
                if (count == 14) {
                    temp == "1" ? tail = true : tail = false;
                }
                // sixteenth input is whether the animal is domesticated
                if (count == 15) {
                    temp == "1" ? domestic = true : domestic = false;
                }
                // eighteenth input is for the animal's type (Bird, Mammal or Fish)
                if (count == 17) {
                    if (temp.front() == '1'){
                        classType = 1;
                    } else if (temp.front() == '2') {
                        classType = 2;
                    } else if (temp.front() == '4') {
                        classType = 4;
                    } else {
                        classType = -1;
                    }
                }
                count++;
            }
            // creates an object and adds to the ZooRecord
            // based on the information gathered from the CSV.file
            switch (classType) {
            case 1:
                this->insert(this->getLength(), new Mammal(hair, toothed, tail, 
                fins, airborne, aquatic, legs, name, domestic, predator));
                break;
            case 2:
                this->insert(this->getLength(), new Bird(airborne, aquatic, name, domestic, predator));
                break;
            case 4:
                this->insert(this->getLength(), new Fish(venomous, name, domestic, predator));
                break;
            default:
                // can ignore the animals that aren't of type mammal, bird or fish
                break;
            }
        }
    } else {
        std::cout << "Cannot open file\n";
    }
    infile.close();
}

/**@post displays all animals in record, one per line by calling appropriate
    object’s display method” **/
void ZooRecord::display() {
    // if the ZooRecord is empty there is nothing to display
    // so it's best to just leave the method
    if (this->isEmpty()) return;

    // iterates through the list
    for (int i = 0; i < this->getLength(); i++){
        // calling the display method of the respective class
        // for each individual Animal in the ZooRecord
        // that method handles the printing of output 
        this->getPointerTo(i)->getItem()->display();
    }
}

/**@post the list is empty and item_count_ == 0*/
void ZooRecord::clear() {
    Node<Animal*>* node_to_delete = first_;
    while (first_ != nullptr)
    {
        first_ = first_->getNext();
        
        // Return node to the system
        node_to_delete->setNext(nullptr);
        node_to_delete->setPrevious(nullptr);
        delete node_to_delete;
        
        node_to_delete = first_;
    }  // end while
    // head_ptr_ is nullptr; node_to_delete is nullptr
    last_ = nullptr;
    item_count_ = 0;
}

/**
@param position indicating point of deletion
@post node at position is deleted, if any. List order is retains
@return true if there is a node at position to be deleted, false otherwise */
bool ZooRecord::remove(size_t position) {
    //get pointer to position
    Node<Animal*>* pos_ptr = getPointerTo(position);
    
    if(pos_ptr == nullptr) return false;
    else {
        // Remove node from chain  
        if (pos_ptr == first_) {
            // Remove first node
            first_ = pos_ptr->getNext();
            first_->setPrevious(nullptr);
            
            // Return node to the system
            pos_ptr->setNext(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        else if (pos_ptr == last_)
        {
            //remove last node
            last_ = pos_ptr->getPrevious();
            last_->setNext(nullptr);
            
            // Return node to the system
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        else {
            //Remove from the middle
            pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
            pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());
            
            // Return node to the system
            pos_ptr->setNext(nullptr);
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        item_count_--;  // decrease count of entries
        return true;
    }
}
