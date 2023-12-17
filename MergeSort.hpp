#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/**
 * @post:Recursise part of merge sort that splits the array into smaller arrays and then merges them to sort the data
 * @param nums: The vector that stores the integers to be sorted
 * @param begin :Iterator to the begining of the vector
 * @param end :Iterator to the last element of the vector
 */

void recursive_merge_sort(std::vector<int>& nums,std::vector<int>::iterator begin,std::vector<int>::iterator end){
    if(begin >= end){
       return;
    }
    int distance = std::distance(begin,end);
    std::vector<int>::iterator mid = begin+(distance/2);          //iterator to the midpoint of the array
    recursive_merge_sort(nums,begin,mid);
    recursive_merge_sort(nums,mid+1,end);
    std::vector<int> left; 
    std::vector<int> right;
    for(std::vector<int>::iterator index = begin; index <= mid ; index++){
        left.push_back(*index);
    }
    for(std::vector<int>::iterator index = mid+1; index <= end ; index++){
        right.push_back(*index);
    }
    std::merge(left.begin(),left.end(),right.begin(),right.end(),begin);
    left.clear();
    right.clear();
}

/**
 * @brief Start of merge sort function
 * @param nums : A vector that stores the data that is being sorted
 * @param duration : A integer value to store the time of the algorithmn 
 * @returns the median of the sorted vector
 */

int mergeSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end();
    std::vector<int> result(nums.size());
    recursive_merge_sort(nums,begin,end-1);
    auto stop = std::chrono::high_resolution_clock::now();
    std::vector<int>::iterator output = begin + nums.size()/2;
    auto length = std::chrono::duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return *output;
}

