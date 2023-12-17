#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>

int standardSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end();
    std::sort(begin,end);
    auto stop = std::chrono::high_resolution_clock::now();
    auto length = std::chrono::duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return *(begin + (end-begin)/2);
}