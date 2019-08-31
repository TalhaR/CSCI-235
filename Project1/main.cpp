#include "Animal.hpp"
#include <iostream>
using std::cout;

int main(){
    Animal a = Animal("Cat", false, true);
    cout << a.getName();
    cout << "\n" << a.isDomestic();
    cout << "\n" << a.isPredator();
    cout << "\n";
    a.setName("Dog");
    a.setDomestic();

    cout << a.getName();
    cout << "\n" << a.isDomestic();
    cout << "\n" << a.isPredator();

    Animal b = Animal();
    cout << "\n" << b.getName();
    cout << "\n" << b.isDomestic();
    cout << "\n" << b.isPredator();
}