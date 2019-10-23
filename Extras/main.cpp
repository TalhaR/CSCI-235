#include "List.hpp"
#include <iostream>

int main() {
    List<int> list = List<int>();
    list.add(1);
    list.add(2);
    list.add(3);
    
    std::cout << "length: " << list.getLength() << "\n";
    
    for (int i = 0; i < list.getLength(); i++) {
        std::cout << list.getItem(i) << "\n";
    }

    std::cout << "\n";
    list.clear();

    std::cout << list.getLength();
    // for (int i = 0; i < list.getLength(); i++) {
    //     std::cout << list.getItem(i) << "\n";
    // }
}