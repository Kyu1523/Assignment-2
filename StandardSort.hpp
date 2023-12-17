#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>

int standardSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end() - nums.size()/2;
    if(nums.size() != 0 && nums.size() % 2 != 0){       //if not even increment end by 1 to get median
        end++;
    }
    std::sort(begin,end);
    auto stop = std::chrono::high_resolution_clock::now();
    auto length = std::chrono::duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return *end;
}