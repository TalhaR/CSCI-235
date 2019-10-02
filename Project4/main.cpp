#include "Animal.hpp"
#include "ArrayBag.hpp"
#include "ZooRecord.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;

int main(){
    std::string path = "zoo.csv";
    ZooRecord animals(path);

    animals.display();
}