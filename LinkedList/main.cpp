#include "LinkedList.hpp"
#include <iostream>

int main(){
    LinkedList<int> list;

    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);

    std::cout << "Position 0: " << list.getEntry(0) << "\n";
    std::cout << "Position 1: " << list.getEntry(1) << "\n";
    std::cout << "Position 2: " << list.getEntry(2) << "\n\n";

    list.rotate(6);

    std::cout << "Position 0: " << list.getEntry(0) << "\n";
    std::cout << "Position 1: " << list.getEntry(1) << "\n";
    std::cout << "Position 2: " << list.getEntry(2) << "\n";

}