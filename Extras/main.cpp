#include "List.hpp"
#include <iostream>

void selectionSort(int*, int);
void insertionSort(int*, int);
void mergeSort(int*, int);

int main() {
    int const SIZE = 4;

    int* arr = new int[SIZE];
    arr[0] = 4;
    arr[1] = 3;
    arr[2] = 2;
    arr[3] = 1;

    mergeSort(arr, SIZE);

    std::cout << "Position 0: " << arr[0] << "\n";
    std::cout << "Position 1: " << arr[1] << "\n";
    std::cout << "Position 2: " << arr[2] << "\n";
    std::cout << "Position 3: " << arr[3] << "\n";
}

void mergeSort(int* arr, int size){
    if ()
}

void selectionSort(int* arr, int size){
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = 1 + i; j < size; j++){
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}