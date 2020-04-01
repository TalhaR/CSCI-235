//  SortingComparisons.hpp
//  Project6
//
//  Created by Tiziana Ligorio on 10/4/19
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************
#ifndef SortingComparison_hpp
#define SortingComparison_hpp

#include <iostream>
#include <cstdlib>
#include <ctime>

//describes the data distribution in the array values_
enum data_distribution {RANDOM, INCREASING, DECREASING};

class SortingComparison {
public:
    //parameterized constructor allocate values_ with array_size
    SortingComparison(size_t array_size);


    /*****************************************************************/
    /********************* SORTING FUNCTIONS *************************/
    /*****************************************************************/

    /**
     @post Sorts an array in ascending order using the selection sort algorithm.
     @return the number of comparisons made by the algorithm
     */
    int selectionSort(int a[], size_t size);

    /**
     @post Sorts an array in ascending order using insertion sort.
     @param a the array to sort
     @param size of the array
     @return the number of comparisons made by the algorithm
     */
    int insertionSort(int a[], size_t size);

    /**
      @post Sorts an array in ascending order using merge sort.
     @param a the array to be sorted
     @param from the first position in the range to sort
     @param to the last position in the range to sort (included)
     @return the number of comparisons made by the algorithm
     */
    int mergeSort(int a[], int from, int to);


    /**
      @post Sorts an array in ascending order using quick sort.
     @param a the array to be sorted
     @param from the first position in the range to sort
     @param to the last position in the range to sort (included)
     @return the number of comparisons made by the algorithm
     */
    int quickSort(int a[], int from, int to);



    /*****************************************************************/
    /****************** TEST FUNCTIONS *******************************/
    /*****************************************************************/


    //*************  DEFINE runComparison HERE!!!! ***********************//
    /**
    @post Sorts a copy of values_ in ascending order with each available sorting functions
    and prints the number of comparisons made by each sorting algorithm
    @param array_type data_distribution of values_ in {RANDOM, INCREASING, DECREASING}
    */
    void runComparison(data_distribution array_type);


private:
    const size_t SIZE; // the size of values_
    int* values_; //an array of integer values to be sorted
    int mergeComparisons = 0; // keeps track of how many comparisons done during MergeSort
    int quicksortComparisons = 0; // keeps track of how many comparisons done during QuickSort

    /**
     @post copies the values_ array to ensure the same array is passed 
     without sorting the original so that each sorting algorithm
     does their respective work on the same array
     @return an array that is identical to values_[]
     */
    int* copyArray();

    /** 
     * @post fills values_[] with Random numbers from 0 to SIZE
     */
    void fillArrayRandom();

    /** 
     * @post fills values_[] with numbers that are increasing from 0 to SIZE
     */
    void fillArrayIncreasing();

    /** 
     * @post fills values_[] with numbers that are decreasing from SIZE to 0
     */
    void fillArrayDecreasing();

    /** 
     * @post prints out the Comparisons done by each sorting algorithm to std::cout
     */
    void printComparisons();

    /** 
     * @post resets the variables 'mergeComparisons' && 'quicksortComparisons' to 0
     */
    void clearComparisons();

    /*****************************************************************/
    /********************* SORTING HELPERS   *************************/
    /*****************************************************************/

    /**
     helper for selectionSort
     @post Gets the position of the smallest element in an array range.
     @param a the array
     @param from the beginning of the range
     @param to the end of the range
     @param count number of comparisons done
     @return the position of the smallest element in
     the range a[from]...a[to]
     */
    int minPosition(int a[], int from, int to, int& count);

    /**
     helper for mergeSort
     @post Merges two adjacent subarrays.
     @param a the array with the elements to merge
     @param from the start of the first subarray
     @param mid the end of the first subarray
     @param to the end of the second subarray
     */
    void merge(int a[], int from, int mid, int to);


    /**
     helper for quickSort
    Partitions a portion of an array.
    @param a the array to partition
    @param from the first index of the portion to be partitioned
    @param to the last index of the portion to be partitioned
    @return the last index of the first partition
    */
    int partition(int a[], int from, int to);

};//end SortingComparison

#endif /* SortingComparison_hpp */
