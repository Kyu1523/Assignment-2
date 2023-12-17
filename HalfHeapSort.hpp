#include <iostream>
#include <vector>
#include <chrono>

/**
 * @post: Fills in the specified hole in the heap
 * @param: A reference to the heap
 * @param: The hole
 */
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole){
    int child;
    int temp;
    int size = heap.size();
    for(int i = 0; i < heap.size();i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
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
    auto start = std::chrono::high_resolution_clock::now();
    nums.push_back(std::move(nums[0]));
    buildHeap(nums);
    for(int i = nums.size() -1 ; i > 0; --i){
        std::swap(nums[0], nums[i]);
        percDown(nums,0);
        nums.erase(nums.begin());
    }
    nums.pop_back();
    auto stop = std::chrono::high_resolution_clock::now();
    auto length = std::chrono::duration_cast<milliseconds>(stop-start);
    duration = length.count();
    return nums[nums.size()/2];
}