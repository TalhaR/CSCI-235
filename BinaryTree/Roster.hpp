#pragma once 
#include "BinaryNode.hpp"
#include "Printer.hpp"
#include <vector>

class Roster {
    private:
    std::shared_ptr<BinaryNode<Student>> rootPtr; 
    
    /** Copy Constructor Helper function
     * @param oldRosterRootPtr the root pointer of another Roster 
     * @return a shared_ptr of type BinaryNode<Student> that will act as the root of another tree
     * @post copies all the contents of the passed in oldRosterRootPtr to a new shared_ptr
     * using a helper function to avoid passing pointers publicly 
     */
    std::shared_ptr<BinaryNode<Student>> copyRoster(const std::shared_ptr<BinaryNode<Student>> oldRosterRootPtr) const;
    
    /** Destructor helper function
     * @param subRosterPtr a shared_ptr of type BinaryNode<Student> that requires deleting
     * @post deletes all subtrees of subRosterPtr and then subRosterPtr
     * using a helper function to avoid passing pointers publicly
     */
    void destroyTree(std::shared_ptr<BinaryNode<Student>> subRosterPtr);
    
    /** Add helper function
     * @param subRosterPtr a shared_ptr of type BinaryNode<Student> in which the newNodePtr will be placed
     * @param newNodePtr a shared_ptr of type BinaryNode<Student> that needs to be placed in the Roster
     * @post places the newNodePtr in the roster such that it retains the properties of a Binary Tree
     */
    auto placeNode(std::shared_ptr<BinaryNode<Student>> subRosterPtr, std::shared_ptr<BinaryNode<Student>> newNodePtr);
    
    /** getHeight helper function
     * @param subRosterPtr a shared_ptr of type BinaryNode<Student> that will be traversed
     * @return the height of the tree
     */
    int getHeightHelper(std::shared_ptr<BinaryNode<Student>> subRosterPtr) const;
    
    /** Display helper function
     * @param visit a variable of type Visitor<Student> 
     * @param rosterPtr a pointer to a BinaryNode that contains a student and is potentially connected to other students
     */
    void inorder(Visitor<Student>& visit, std::shared_ptr<BinaryNode<Student>> rosterPtr) const;
    
    std::shared_ptr<BinaryNode<Student>> removeValue(std::shared_ptr<BinaryNode<Student>> subRosterPtr, Student student);
    
    std::shared_ptr<BinaryNode<Student>> removeNode(std::shared_ptr<BinaryNode<Student>> nodePtr);
    
    std::shared_ptr<BinaryNode<Student>> removeLeftmostNode(std::shared_ptr<BinaryNode<Student>> nodePtr, Student& inorderSuccessor);
    
    public:
    Roster() = default;
    
    /** Destructor 
     * @post deletes all the contents of Roster 
     */
    ~Roster();
    
    /** COPY CONSTRUCTOR 
     * @param anotherRoster roster object to be copied
     */
    Roster(const Roster& anotherRoster);
    
    /**
     * @return true if the Roster is empty
     *         false if the Roster has students 
     */
    bool isEmpty(); 
    
    /**
     * @pre student must be unique. (i.e. cannot share the same full name as another student in Roster)
     * @param student a student to be added to the Roster
     * @post
     */
    void add(Student student);
    /**
     * @param students a vector of students to be added to the roster
     * @post adds all students in the students vector into the Roster
     */
    void add(std::vector<Student> students);
    /**
     * @param student a student to be removed from Roster
     * @post specified student is no longer apart of the roster
     */
    void remove(Student student);
    /**
     * @return an integer which represents the height of the tree for the Roster
     */
    int getHeight();
    /**
     * @post prints all students inorder (as per inorder traversal), one per
     *       line, separated by comma (i.e. "id, first_name, last_name\n") 
     */
    void display();
    
    
    // EXTRA CREDIT
    
    void rotateLeft();
    
    void rotateRight();
};