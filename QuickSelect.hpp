#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

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
    while(low < high){
        if(*low <= *pivot){
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
    return low;
}

void recursive_quick_select(std::vector<int>& nums, std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(end - begin <= 10){
        std::sort(begin,end);
    }
    std::vector<int>::iterator pivot = choosePivot(begin,end);
    iter_swap(pivot,end);
    pivot = hoarePartition(nums,begin,end);
    std::vector<int>::iterator mid = nums.begin() + nums.size()/2;
    if(pivot < mid){
        recursive_quick_select(nums,pivot+1,end);
    }
    else if(pivot > mid){
        recursive_quick_select(nums,begin,pivot-1);
    }
    else{
        return;
    }
}

int quickSelect ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();
    recursive_quick_select(nums,nums.begin(),nums.end()-1);

    auto stop = std::chrono::high_resolution_clock::now();
    auto length = std::chrono::duration_cast<milliseconds>(stop-start);
    duration = length.count();
    int mid = nums.size()/2;
    if(nums.size()%2 == 1){
        mid--;
    }
    return nums[mid];
}