#include "Animal.hpp"
#include "Fish.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "List.hpp"
#include "ZooRecord.hpp"
#include <iostream>
using std::cout;

int main(){
    std::string path = "test.csv";
    ZooRecord animals(path);

    animals.display();

    cout << "done\n";

    cout << animals.getLength();
}