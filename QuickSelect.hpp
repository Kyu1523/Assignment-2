#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

/**
 * @brief: Chooses the pivot as the median of the beginning element, middle element or end element
 * 
 * @param begin: a iterator to the beginning of the vector to choose the pivot from
 * @param end :a iterator to the end ofhte vecotr to choose the pivot from
 * @return: A iterator to the pivot
 */
std::vector<int>::iterator choosePivot(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    std::vector<int>::iterator pivot;
    std::vector<int>::iterator mid = begin + (end-begin)/2;
    if(*begin <= *end){
        if(*mid <= *begin){
            pivot = begin;
        }
        else{
            pivot = mid;     //mid is greater than low
        }
    }
    else if (*end < *begin){
        if(*mid < *end){
            pivot = end;
        }
        else{
            pivot = mid;    //mid is greater than high
        }
    }
    return pivot;
}
/**
 * @post:Partitions the array using the median of the first, middle and last element
 * 
 * @param nums: The array to be partitioned
 * @param low: The begining iterator
 * @param high: The end iterator, which is the pivot
 * @return: A iterator to the pivot 
 */
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    std::vector<int>::iterator pivot = high;
    high--;                 //to not include the pivot
    while(low <= high){
        if(*low < *pivot){
            low++;
        }
        else if(*high > *pivot){
            high--;
        }
        else{
            iter_swap(low,high);
            low++;
            high--;
        }
    }
    iter_swap(low,pivot);       //swap pivot into place
    return low;
}


/**
 * @post: Will recursively run quickselect until median is found
 * @param nums : The vector that stores the data
 * @param begin : Beginning iterator of the range to partition
 * @param end : End iterator of the range to partition
 */
void recursive_quick_select(std::vector<int>& nums, std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(end+1 - begin <= 10){
        std::sort(begin,end);
        return;
    }
    std::vector<int>::iterator pivot = choosePivot(begin,end);
    iter_swap(pivot,end);                               //places pivot into the end for hoarePartition
    pivot = hoarePartition(nums,begin,end);             //places pivot back into pivot iterator
    std::vector<int>::iterator mid = nums.begin() + nums.size()/2;
    if(pivot < mid){                                //if pivot is less than midpoint, then median is on the right of pivot
        recursive_quick_select(nums,pivot+1,end);
    }
    else if(pivot > mid){                           //if pivot is greater than midpoint, then median is on the left of pivot
        recursive_quick_select(nums,begin,pivot-1);
    }
    else{
        return;                                     //median is found
    }
}

/**
 * @brief QuickSelect function
 * @param nums : Vector that we want the median from
 * @param duration : A int to store the duration of the algorithm
 * @return : The median of nums
 */
int quickSelect ( std::vector<int>& nums, int& duration ){
    auto start = high_resolution_clock::now();
    recursive_quick_select(nums,nums.begin(),nums.end()-1);
    auto stop = high_resolution_clock::now();
    auto length = duration_cast<milliseconds>(stop-start);
    duration = length.count();
    int mid = nums.size()/2;
    if(nums.size()%2 == 0){
        mid--;
    }
    return nums[mid];
}