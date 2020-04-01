#include "SortingComparison.hpp"
#include <iostream>

int values_[4] = {4, 3, 2, 1};

int* copyArray() {
    // copys the values_ array to 
    // another array and returns that copy
    int* arrayCopy = new int[4];
    for(int i = 0; i < 4; i++) {
        arrayCopy[i] = values_[i];
    }
    return arrayCopy;
}

int main() {
    SortingComparison sc(100);

    int arr[4] = {4, 3, 2, 1};

    sc.runComparison(RANDOM);
    
    // std::cout << "Pos 0: " << values_[0] << "\n";
    // std::cout << "Pos 1: " << values_[1] << "\n";
    // std::cout << "Pos 2: " << values_[2] << "\n";
    // std::cout << "Pos 3: " << values_[3] << "\n\n";

    // std::cout << "Comprasions: " << sc.insertionSort(copyArray(), 4) << "\n";

    // std::cout << "Pos 0: " << values_[0] << "\n";
    // std::cout << "Pos 1: " << values_[1] << "\n";
    // std::cout << "Pos 2: " << values_[2] << "\n";
    // std::cout << "Pos 3: " << values_[3] << "\n\n";

    
}