// Name: Talha Rahman
// Course: CSCI-235     Professor Ligorio
// Project 3

// This is the implementation file for the ZooRecord class
#include "ZooRecord.hpp"
#include <fstream>
#include <sstream>

template<class T>
ZooRecord<T>::ZooRecord(std::string input_file_name){
    std::ifstream infile;
    infile.open(input_file_name);
    

    if(infile.good()){
        std::string name, line, s, temp;
        bool predator, domestic;
        int class_type;
        // get rid of first line
        getline(infile, temp);

        while(getline(infile, line)){
            std::stringstream s(line);
            int count = 0;
        
            while(getline(s, temp, ',')){
                if (count == 0) name = temp;
                if (count == 7) {
                    if (temp == "1") {
                        predator = true;
                    } else {
                        predator = false;
                    }
                }
                if (count == 15) {
                    if (temp == "1"){
                        domestic = true;
                    } else {
                        domestic = false;
                    }
                }
                if (count == 17){
                    if (temp == "1") {
                        class_type = 1;
                    } if (temp == "2") {
                        class_type = 2;
                    } else if (temp == "4") {
                        class_type = 4;
                    } else {
                        class_type = 3;
                    }
                }
                count++;
            }
            switch (class_type){
                case 1 :
                this->add(Mammal(name, domestic, predator));
                break;
                case 2 :
                this->add(Bird(name, domestic, predator));
                case 4 :
                this->add(Fish(name, domestic, predator));
                default :
                this->add(Animal(name, domestic, predator));
            }
        }
    } else {
        std::cout << "Cannot open file\n";
    }
    infile.close();
}

template<class T>
void ZooRecord<T>::display() {
    // if the ZooRecord is empty there is nothing to display
    // so it's best to just leave the method
    if (this->isEmpty()) return;

    // iterates through the arraybag starting from 0
    // working up to the item_count_ and calls the
    // respective Animal's display method to print 
    // what their name is along with if they're a 
    // predator or domesticated.
    for (int i = 0; i < this->item_count_; i++){
        this->items_[i].display();
    }
}


//  if(infile.good()){
//         std::string name;
//         bool hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbone,breathes,venomous,fins,tail,domestic,catsize;
//         int legs, class_type;
//         while(infile.good()){
//             scanf("%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
//             hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbone
//             ,breathes,venomous,fins,legs,tail,domestic,catsize,class_type);

//             switch (class_type){
//                 //case 1 :

//             }
//         }
//     } else {
//         std::cout << "Cannot open file\n";
//     }

// template<class T>
// ZooRecord<T>::ZooRecord(std::string input_file_name){
//     std::ifstream infile;
//     infile.open(input_file_name);
    

//     if(infile.good()){
//         std::string name;
//         bool hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbone,breathes,venomous,fins,tail,domestic,catsize;
//         int legs, class_type;
//         getline(infile, name);

//         while(infile >> name >> hair >> feathers >> eggs >> milk >> airborne >> aquatic
//         >> predator >> toothed >> backbone >> breathes >> venomous >> fins >> legs
//         >> tail >> domestic >> catsize >> class_type){
//             switch (class_type){
//                 case 1 :
//                 this->add(Mammal(name, domestic, predator));
//                 break;
//                 case 2 :
//                 this->add(Bird(name, domestic, predator));
//                 case 4 :
//                 this->add(Fish(name, domestic, predator));
//                 default :
//                 this->add(Animal(name, domestic, predator));
//             }
//         }
//     } else {
//         std::cout << "Cannot open file\n";
//     }
//     infile.close();
// }