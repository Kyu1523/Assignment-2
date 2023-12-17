#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
/**
 * @post: Fills in the specified hole in the heap
 * @param: A reference to the heap
 * @param: The hole that is to be filled
 */
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole){
    int child;
    int temp;
    int size = heap.size();
    for(temp = std::move(heap[hole]); 2*hole+1 < size; hole = child){
        child = 2 * hole + 1;
        if(child != size-1 && heap[child] < heap[child+1]){
            ++child;
        }
        if(temp < heap[child]){
            heap[hole] = std::move(heap[child]);
        }
        else{
            break;
        }
    }
    heap[hole] = std::move(temp);
}


/**
 * @brief Builds the heap
 * @param:The heap
 */
void buildHeap (std::vector<int>& heap){
    for(int i = heap.size()/2 - 1; i >= 0; --i){
        percDown(heap,i);
    }
}

int halfHeapSort(std::vector<int>& nums,int& duration){
    auto start = high_resolution_clock::now();
    nums.push_back(std::move(nums[0]));
    buildHeap(nums);
    for(int i = nums.size() ; i > nums.size()/2; --i){
        std::swap(nums[0], nums[i]);
        percDown(nums,0);
        nums.erase(nums.begin());
    }
    auto stop = high_resolution_clock::now();
    auto length = duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return nums[nums.size()/2];
}