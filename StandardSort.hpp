#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std::chrono;
int standardSort(std::vector<int>& nums, int& duration ){
    auto start = high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end();
    std::sort(begin,end);
    auto stop = high_resolution_clock::now();
    auto length = duration_cast<milliseconds>(stop-start);
    duration = length.count();
    std::vector<int>::iterator mid = begin + (end-begin)/2;
    if(nums.size() % 2 == 1){
        mid++;
    }
    return *mid;
}