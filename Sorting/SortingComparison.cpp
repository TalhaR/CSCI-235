//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************


#include "SortingComparison.hpp"


//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]){}



/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/



/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @param count number of comparisons done
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to, int& count)
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++) {
        if (a[i] < a[min_pos]) { min_pos = i;}
        count++;
    }
    return min_pos;
}


/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::selectionSort(int a[], size_t size) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        // Find the position of the minimum
        int min_pos = minPosition(a, i, static_cast<int>(size - 1), count);
        // Swap the next element and the minimum
        std::swap(a[i], a[min_pos]);
    }

    return count;
}


/*************** INSERTION SORT **************************/

/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
 */
int SortingComparison::insertionSort(int a[], size_t size) {
    // keeps track of how many comparisons done
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        int next = a[i];
        // Move all larger elements up
        int j = i;
        while (j > 0 && a[j - 1] > next) {
            count++;
            a[j] = a[j - 1];
            j--;
        }
        
        // Insert the element
        a[j] = next;
    }

    return count;
}


/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to) {
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to) {
        if (a[i1] < a[i2]) {
            temp_array[j] = a[i1];
            i1++;
        } else {
            temp_array[j] = a[i2];
            i2++;
        }
        mergeComparisons++;
        j++;
    }

    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid) {
        temp_array[j] = a[i1];
        mergeComparisons++;
        i1++;
        j++;
    }
    // Copy any remaining entries of the second half
    while (i2 <= to) {
        temp_array[j] = a[i2];
        mergeComparisons++;
        i2++;
        j++;
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++) {
        a[from + j] = temp_array[j];
    }

    delete[] temp_array;
}

/**
 @post Sorts the elements in a range of a array.
 @param a the array with the elements to sort
 @param from the first position in the range to sort
 @param to the last position in the range to sort (included)
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::mergeSort(int a[], int from, int to) {
    if (from == to) { return 0; }
    int mid = (from + to) / 2;
    // int count = 0;

    // Recursively sort the first and the second half
    mergeSort(a, from, mid);
    mergeSort(a, mid + 1, to);
    merge(a, from, mid, to);

    return mergeComparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* QUICK SORT + HELPER**************************/

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to)
{
    int pivot = a[from];
    int i = from - 1; //index of data item being compared from left
    int j = to + 1;   //index of data item being compared from right
    while (i < j) {   // as long as i and j did not cross (meet)
        i++;
        while (a[i] < pivot) {//increment i until a[i] >= pivot
            i++;
            quicksortComparisons++;
        }
        j--;
        while (a[j] > pivot) {//decrement j until a[j] <= pivot
            j--;
            quicksortComparisons++;
        }
        if (i < j) {
            std::swap(a[i], a[j]);
        }
   }
   return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to) {
    if (from >= to){return 0;}

    int p = partition(a, from, to);
    quickSort(a, from, p);
    quickSort(a, p + 1, to);

    return quicksortComparisons;
}



/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/

/**
    @post Sorts a copy of values_ in ascending order with each available sorting functions
    and prints the number of comparisons made by each sorting algorithm
    @param array_type data_distribution of values_ in {RANDOM, INCREASING, DECREASING}
*/
void SortingComparison::runComparison(data_distribution array_type) {
    switch (array_type)
    {
    case RANDOM:
        fillArrayRandom();
        printComparisons();
        clearComparisons();
        break;
    case INCREASING:
        fillArrayIncreasing();
        printComparisons();
        clearComparisons();
        break;
    case DECREASING:
        fillArrayDecreasing();
        printComparisons();
        clearComparisons();
        break;
    default:
        std::cout << "Incorrect array_type requested\n";
        break;
    }
}

/** 
 * @post resets the variables 'mergeComparisons' && 'quicksortComparisons' to 0
*/
void SortingComparison::clearComparisons() {
    mergeComparisons = 0;
    quicksortComparisons = 0;
}

/** 
 * @post fills values_[] with Random numbers from 0 to SIZE
*/
void SortingComparison::fillArrayRandom() {
    // using srand with the time to generate "true" 
    // randomness because rand() on it's own is 
    // only pseudo random. Using NULL instead of 0
    // because it is faster
    srand(static_cast<unsigned>(time(NULL)));
    for (int i = 0; i < SIZE; i++){
        values_[i] = rand() % SIZE;
    }
}

/** 
 * @post fills values_[] with numbers that are increasing from 0 to SIZE
 */
void SortingComparison::fillArrayIncreasing() {
    for (int i = 0; i < SIZE; i++) {
        values_[i] = i;
    }
}

/** 
 * @post fills values_[] with numbers that are decreasing from SIZE to 0
 */
void SortingComparison::fillArrayDecreasing() {
    int j = 0;
    for (int i = SIZE; i > 0; i--) {
        values_[j] = i;
        j++;
    }
}

/**
    @post copies the values_ array to ensure the same array is passed 
    without sorting the original so that each sorting algorithm
    does their respective work on the same array
    @return an array that is identical to values_[]
*/
int* SortingComparison::copyArray() {
    // copys the values_ array to 
    // another array and returns that copy
    int* arrayCopy = new int[SIZE];
    for(int i = 0; i < SIZE; i++) {
        arrayCopy[i] = values_[i];
    }
    return arrayCopy;
}

/** 
 * @post prints out the Comparisons done by each sorting algorithm to std::cout
 */
void SortingComparison::printComparisons() {
    std::cout << "Selection sort comparisons: " << selectionSort(copyArray(), SIZE) << "\n\n";
    std::cout << "Insertion sort comparisons: " << insertionSort(copyArray(), SIZE) << "\n\n";
    std::cout << "Merge sort comparisons: " << mergeSort(copyArray(), 0, SIZE - 1) << "\n\n";
    std::cout << "Quick sort comparisons: " << quickSort(copyArray(), 0, SIZE - 1) << "\n\n";
}