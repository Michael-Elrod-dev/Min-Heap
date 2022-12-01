#include "minHeap.h"
#include <vector>
#include <iostream>

void minHeap::siftUp(int pos){
    int parent = (pos - 1) / 2;
    int child = pos;

    while(child != 0 && heap[parent] > heap[child]) {
        // Swap child and parent
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = (parent - 1) / 2;
    }
}


void minHeap::siftDown(int pos){
    int parent = pos;
    // Get left and right of parent
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int swap = -1;
    int temp;

    //checking left child
    if(leftChild < (int)heap.size() && heap[leftChild] < heap[parent])
        swap = leftChild;

    //checking right child
    if(rightChild < (int)heap.size() && heap[rightChild] < heap[parent])
        if (swap == -1)
            swap = rightChild;
    // Take the minimum
    else if (heap[rightChild] < heap[leftChild])
        swap=rightChild;

    // No swap needed
    if(swap == -1)
        return;

    // Swap parent with swap value
    temp = heap[parent];
    heap[parent] = heap[swap];
    heap[swap] = temp;
    siftDown(swap);
}


minHeap::minHeap(vector<int> data){
    // Clean heap
    heap.resize(0);

    // Fill vector
    for(int & i : data)
        heap.push_back(i);

    for(int i=heap.size()-1;i>=0;i--)
        siftDown(i);
}


void minHeap::insert(int value){
    // Insert at back of vector
    heap.push_back(value);
    int position = heap.size()-1;
    // Move last element up
    siftUp(position);
}


int minHeap::removeMin(){
    int temp;

    // Check if heap is empty
    if(heap.empty())
        return -1;

    // Swap head with last element
    temp = heap[0];
    heap[0] = heap[heap.size()-1];
    heap[heap.size()-1] = temp;
    heap.pop_back();
    siftDown(0);
    return temp;
}

/*
int main()
{
    vector<int> input={1,2,3,4,5,11,12,13,14,15};
    vector<int> test={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> heapTest;

    for (int i=9; i>0; i--) swap(input[i], input[rand()%i]);

    minHeap h(input);

    h.insert(6);
    h.insert(10);
    h.insert(7);
    h.insert(9);
    h.insert(8);

    for (int i=0; i<15; i++) heapTest.push_back(h.removeMin());

    //ASSERT_THAT(heapTest, ElementsAreArray(test));
    for (int i=0; i<15; i++)
    {
        if (heapTest[i] != test[i])
        {
            std::cout << "Mismatch in heapTest at position " << i << ": expected/correct value " << test[i] << ", actual value when testing " << heapTest[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}
 */