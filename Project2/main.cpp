#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include <iostream>
using std::cout;

int main(){
    // Animal a = Animal("a", false, true);
    // cout << a.getName() << "\n";
    // cout << a.isDomestic() << "\n";
    // cout << a.isPredator() << "\n\n";

    Mammal m = Mammal("lion");
    cout << m.getName() << "\n";
    cout << m.isDomestic() << "\n";
    cout << m.isPredator() << "\n\n";

    // Fish m = Fish("m", true, true);
    // cout << m.getName() << "\n";
    // cout << m.isDomestic() << "\n";
    // cout << m.isPredator() << "\n\n";
    
    cout << m.legs() << "\n\n";


}