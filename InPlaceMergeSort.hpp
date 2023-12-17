#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
/**
 * @post:Recursise part of merge sort that splits the array into smaller arrays and then merges them to sort the data
 * @param nums: The vector that stores the integers to be sorted
 * @param begin :Iterator to the begining of the vector
 * @param end :Iterator to the last element of the vector
 */

void recursive_inplace_merge_sort(std::vector<int>::iterator begin,std::vector<int>::iterator end){
    if(end - begin <= 1){
        return;
    }
    std::vector<int>::iterator mid = begin + (end-begin)/2;
    recursive_inplace_merge_sort(begin,mid);
    recursive_inplace_merge_sort(mid,end);
    std::inplace_merge(begin,mid,end);
}

/**
 * @param nums : A vector that stores the data that is being sorted
 * @param duration : A integer value to store the time of the algorithmn 
 * @returns the median of the sorted vector
 */
int inPlaceMergeSort (std::vector<int>& nums, int& duration ){
    auto start = high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end();
    recursive_inplace_merge_sort(begin,end);
    auto stop = high_resolution_clock::now();
    std::vector<int>::iterator result = begin + nums.size()/2;
    auto length = duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return *result;
}

