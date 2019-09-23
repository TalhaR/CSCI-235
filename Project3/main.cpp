#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include "ArrayBag.hpp"
#include "ZooRecord.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;

int main(){
    std::string path = "zoo.csv";
    ZooRecord<Animal> animals(path);

    animals.display();
}