#include "Roster.hpp"

int main() {
    Roster roster;
    
    Student s1 = Student(1, "talha", "rahman");
    Student s2 = Student(1, "talha", "rahman");
        
    std::cout << roster.getHeight() << "\n";
    
    roster.add(s1);
    roster.add(s2);
    
    std::cout << roster.getHeight() << "\n";
    
}