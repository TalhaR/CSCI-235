#include "Roster.hpp"

/** Destructor 
 * @post deletes all the contents of Roster 
 */
Roster::~Roster() {
    destroyTree(rootPtr); // calls helper function
}

/** Copy Constructor Helper function
 * @param oldRosterRootPtr the root pointer of another Roster 
 * @return a shared_ptr of type BinaryNode<Student> that will act as the root of another tree
 * @post copies all the contents of the passed in oldRosterRootPtr to a new shared_ptr
 * using a helper function to avoid passing pointers publicly 
 */
std::shared_ptr<BinaryNode<Student>> Roster::copyRoster(const std::shared_ptr<BinaryNode<Student>> oldRosterRootPtr) const {
    std::shared_ptr<BinaryNode<Student>> newRosterPtr;
    
    // Copies Roster with nodes during a preorder traversal
    if (oldRosterRootPtr != nullptr) {
        newRosterPtr = std::make_shared<BinaryNode<Student>>(oldRosterRootPtr->getItem(), nullptr, nullptr); // copies node
        newRosterPtr->setLeftChildPtr(copyRoster(oldRosterRootPtr->getLeftChildPtr())); // copies left side of Roster
        newRosterPtr->setRightChildPtr(copyRoster(oldRosterRootPtr->getRightChildPtr())); // copies right side of Roster
    }
    
    return newRosterPtr;
}

/** COPY CONSTRUCTOR 
 * @param anotherRoster roster object to be copied
 */
Roster::Roster(const Roster& anotherRoster) {
    rootPtr = copyRoster(anotherRoster.rootPtr); // calls helper function
}

/** Destructor helper function
 * @param subRosterPtr a shared_ptr of type BinaryNode<Student> that requires deleting
 * @post deletes all subtrees of subRosterPtr and then subRosterPtr
 * using a helper function to avoid passing pointers publicly
 */
void Roster::destroyTree(std::shared_ptr<BinaryNode<Student>> subRosterPtr) {
    // have to call delete in Postorder to make sure 
    // all subtrees are deleted without memory leaks
    if (subRosterPtr != nullptr) {
        destroyTree(subRosterPtr->getLeftChildPtr()); // recursive call to delete left 
        destroyTree(subRosterPtr->getRightChildPtr()); // recursive call to delete right
        subRosterPtr.reset(); 
    }
}

/**
 * @return true if the Roster is empty
 *         false if the Roster has students 
 */
bool Roster::isEmpty() {
    return rootPtr == nullptr;
}

/** Add helper function
 * @param subRosterPtr a shared_ptr of type BinaryNode<Student> in which the newNodePtr will be placed
 * @param newNodePtr a shared_ptr of type BinaryNode<Student> that needs to be placed in the Roster
 * @post places the newNodePtr in the roster such that it retains the properties of a Binary Tree
 */
auto Roster::placeNode(std::shared_ptr<BinaryNode<Student>> subRosterPtr, std::shared_ptr<BinaryNode<Student>> newNodePtr) {
    if (subRosterPtr == nullptr) {
        return newNodePtr;
    } else {
        std::string studentName = newNodePtr->getItem().getLastName() + newNodePtr->getItem().getFirstName();
        std::string currentName = subRosterPtr->getItem().getLastName() + subRosterPtr->getItem().getFirstName();
        
        if (currentName > studentName) {
            subRosterPtr->setLeftChildPtr(placeNode(subRosterPtr->getLeftChildPtr(), newNodePtr));
        } else {
            subRosterPtr->setRightChildPtr(placeNode(subRosterPtr->getRightChildPtr(), newNodePtr));
        }
        return subRosterPtr;
    }
}

/**
 * @pre student must be unique. (i.e. cannot share the same full name as another student in Roster)
 * @param student a student to be added to the Roster
 * @post
 */
void Roster::add(Student student) {
    if (rootPtr == nullptr) {
        rootPtr = std::make_shared<BinaryNode<Student>>(student);
    } else {
        auto newNodePtr = std::make_shared<BinaryNode<Student>>(student);
        placeNode(rootPtr, newNodePtr);
    }
}

/**
 * @param students a vector of students to be added to the roster
 * @post adds all students in the students vector into the Roster
 */
void Roster::add(std::vector<Student> students) {
    // for each student in the vector
    // calls add function to place student in Roster
    for (int i = 0; i < students.size(); i++) {
        add(students[i]);
    }
}

std::shared_ptr<BinaryNode<Student>> Roster::removeLeftmostNode(std::shared_ptr<BinaryNode<Student>> nodePtr, Student& inorderSuccessor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }
}

std::shared_ptr<BinaryNode<Student>> Roster::removeNode(std::shared_ptr<BinaryNode<Student>> nodePtr) {
    if (nodePtr->isLeaf()) {
        nodePtr.reset();
        return nodePtr;
    } else if (nodePtr->getLeftChildPtr() == nullptr) {
        return nodePtr->getRightChildPtr();
    } else if (nodePtr->getRightChildPtr() == nullptr) {
        return nodePtr->getLeftChildPtr();
    } else {
        Student newNodePtr(1, "", "");
        
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodePtr));
        nodePtr->setItem(newNodePtr);
        return nodePtr;
    }
    
}

std::shared_ptr<BinaryNode<Student>> Roster::removeValue(std::shared_ptr<BinaryNode<Student>> subRosterPtr, Student student) {
    if (subRosterPtr == nullptr) return subRosterPtr;
    
    std::string studentName = student.getLastName() + student.getFirstName();
    std::string currentName = subRosterPtr->getItem().getLastName() + subRosterPtr->getItem().getFirstName();
    
    if (studentName == currentName) {
        subRosterPtr = removeNode(subRosterPtr);
        return subRosterPtr;
    } else {
        if (currentName > studentName) {
            subRosterPtr->setLeftChildPtr(removeValue(subRosterPtr->getLeftChildPtr(), student));
        } else {
            subRosterPtr->setRightChildPtr(removeValue(subRosterPtr->getRightChildPtr(), student));
        }
    }
    return subRosterPtr;
}

/**
 * @param student a student to be removed from Roster
 * @post specified student is no longer apart of the roster
 */
void Roster::remove(Student student) {
    removeValue(rootPtr, student);
}

/**
 * @return an integer which represents the height of the tree for the Roster
 */
int Roster::getHeight() {
    return getHeightHelper(rootPtr);
}

/** Add helper function
 * @param subRosterPtr a shared_ptr of type BinaryNode<Student> that will be traversed
 * @return the height of the tree
 */
int Roster::getHeightHelper(std::shared_ptr<BinaryNode<Student>> subRosterPtr) const {
    if (subRosterPtr == nullptr) return 0;
    else { 
        return 1 + std::max(getHeightHelper(subRosterPtr->getLeftChildPtr()), getHeightHelper(subRosterPtr->getRightChildPtr()));
    }
}

/** Display helper function
 * @param visit a variable of type Visitor<Student> 
 * @param rosterPtr a pointer to a BinaryNode that contains a student and is potentially connected to other students
 */
void Roster::inorder(Visitor<Student>& visit, std::shared_ptr<BinaryNode<Student>> rosterPtr) const {
    if (rosterPtr != nullptr) {
        inorder(visit, rosterPtr->getLeftChildPtr());
        Student student = rosterPtr->getItem();
        visit(student);
        inorder(visit, rosterPtr->getRightChildPtr());
    }
}

/**
 * @post prints all students inorder (as per inorder traversal), one per
 *       line, separated by comma (i.e. "id, first_name, last_name\n") 
 */
void Roster::display() {
    Printer visit;
    inorder(visit, rootPtr);
}


// EXTRA CREDIT

void Roster::rotateLeft() {
    
}
    
void Roster::rotateRight() {
    
}