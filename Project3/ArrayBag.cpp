//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"
#include <iostream>
#include <vector>

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor

template<class T>
void ArrayBag<T>::display() const {
   // if the bag is empty there is nothing to display
   // so it's best to just leave the method
   if (this->isEmpty()) return;

   // iterates through the arraybag starting from 0
   // working up to the item_count_ and prints out 
   // to std::cout and will add "\n" at the end 
   for (int i = 0; i < item_count_; i++){
      if (i == item_count_-1) {
         std::cout << items_[i] << "\n"; 
      } else {
         std::cout << items_[i] << ", ";
      }
   }
}

template<class T>
void ArrayBag<T>::operator+=(const ArrayBag<T>& a_bag){
   // converting a_bag to a vector to allow for easy
   // iteration through. Upon iteration with an enhanced
   // for loop, this will add each element into the 
   // original ArrayBag
   std::vector<T> temp = a_bag.toVector();
   for (T& x : temp){
      this->add(x);
   }
}

template<class T>
void ArrayBag<T>::operator-=(const ArrayBag<T>& a_bag){
   // Nearly identical to += but removal instead.

   // converting a_bag to a vector to allow for easy
   // iteration through. Upon iteration with an enhanced
   // for loop, this will remove each element into the 
   // original ArrayBag
   std::vector<T> temp = a_bag.toVector();
   for (T& x : temp){
      this->remove(x);
   }
}

template<class T>
void ArrayBag<T>::operator/=(const ArrayBag<T>& a_bag){
   // converts the original ArrayBag to a vector 
   // this allows easy iteration through the bag. 
   // iterating through the vector, it checks if 
   // that elemenet exists in the a_bag, if it does
   // not then it will remove it from the original 
   // ArrayBag. 
   std::vector<T> temp = this->toVector();
   for (T& x : temp){
      if (!a_bag.contains(x)){
         this->remove(x);
      }
   }
}

/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
   // checks if the new entry already exists inside
   // the ArrayBag. If it does then it will not be 
   // added again. This makes the ArrayBag like a 
   // Set since every element will be unique.
   if (this->contains(new_entry)) return false;

	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
        return true;
	}  // end if

	return false;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if

	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if

      cun_index++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);

   return bag_contents;
}  // end toVector


// ********* PRIVATE METHODS **************//

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;

   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf