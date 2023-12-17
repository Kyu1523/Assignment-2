#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>
using namespace std::chrono;

int halfSelectionSort ( std::vector<int>& nums, int& duration ){
    auto start = high_resolution_clock::now();
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end()-1;
    std::vector<int>::iterator mid = begin + (end - begin)/2;
    for(begin; begin < end;begin++){
        std::vector<int>::iterator smallest = begin;
        for(std::vector<int>::iterator index = begin; index < end; index++){
            if(*index < *smallest){
                smallest = index;
            }
        }
        std::iter_swap(begin,smallest);
    }
    auto stop = high_resolution_clock::now();
    auto length = duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return *mid;
}